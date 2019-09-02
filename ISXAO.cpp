//
// ISXAO
//

// Version guideline: YYYYMMDD
// Add lettering to the end to indicate a new version on the same date, such as 20060305a, 20060305b, etc
// You can also use a standard version numbering system such as 1.00, 1.01, etc. 
// Be aware that for the versioning system, this text is simply compared to another version text from the 
// same extension to check for new versions -- if this version text comes before the compared text (in a 
// dictionary), then an update is available.  Equal text means the version is up to date.  After means this 
// is newer than the compared version.  With that said, use whatever version numbering system you'd like.
#define EXTENSION_VERSION "20160602"

#include "isxao_main.h"
#include <sstream>
#pragma comment(lib,"isxdk.lib")
// The mandatory pre-setup function.  Our name is "ISXAO", and the class is ISXAO.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXAO",ISXAO);

// Basic LavishScript datatypes, these get retrieved on startup by our initialize function, so we can
// use them in our Top-Level Objects or custom datatypes
LSType *pStringType=0;
LSType *pIntType=0;
LSType *pUintType=0;
LSTypeDefinition *pInt64Type=0;
LSTypeDefinition *pInt64PtrType=0;
LSType *pBoolType=0;
LSType *pfloatType=0;
LSType *pTimeType=0;
LSType *pByteType=0;
LSType *pIntPtrType=0;
LSType *pBoolPtrType=0;
LSType *pfloatPtrType=0;
LSTypeDefinition *pfloat64PtrType=0;
LSType *pBytePtrType=0;
LSTypeDefinition *pPoint3fType=0;
LSTypeDefinition *pIndexType=0;
LSTypeDefinition *pVectorType=0;
LSTypeDefinition *pMapType=0;
LSTypeDefinition *pSetType=0;


ISInterface *pISInterface=0;
HISXSERVICE hPulseService;
HISXSERVICE hMemoryService;
HISXSERVICE hHTTPService;
HISXSERVICE hTriggerService;
HISXSERVICE hSystemService;

char AO_Version[]=EXTENSION_VERSION;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl TriggerService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl HTTPService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl SystemService(bool Broadcast, unsigned int MSG, void *lpData);


// The constructor of our class.  General initialization cannot be done yet, because we're not given
// the pointer to the Inner Space interface until it is ready for us to initialize.  Just set the
// pointer we have to the interface to 0.  Initialize data members, too.
ISXAO::ISXAO(void)
{
}

// Free any remaining resources in the destructor.  This is called when the DLL is unloaded, but
// Inner Space calls the "Shutdown" function first.  Most if not all of the shutdown process should
// be done in Shutdown.
ISXAO::~ISXAO(void)
{
}

// Initialize is called by Inner Space when the extension should initialize.
bool ISXAO::Initialize(ISInterface *p_ISInterface)
{
	/* 
	 * Most of the functionality in Initialize is completely optional and could be removed or
	 * changed if so desired.  The defaults are simply a suggestion that can be easily followed.
	 */

	__try // exception handling. See __except below.
	{
		// Keep a global copy of the ISInterface pointer, which is for calling Inner Space API
		pISInterface=p_ISInterface;

		// Register the extension to make launching and updating the extension easy
		RegisterExtension();

		// retrieve basic LavishScript data types for use in ISXAO data types
		pStringType=pISInterface->FindLSType("string");
		pIntType=pISInterface->FindLSType("int");
		pUintType=pISInterface->FindLSType("uint");
		pInt64Type = pISInterface->FindLSType("int64");
		pInt64PtrType = pISInterface->FindLSType("int64ptr");
		pBoolType=pISInterface->FindLSType("bool");
		pfloatType=pISInterface->FindLSType("float");
		pTimeType=pISInterface->FindLSType("time");
		pByteType=pISInterface->FindLSType("byte");
		pIntPtrType=pISInterface->FindLSType("intptr");
		pBoolPtrType=pISInterface->FindLSType("boolptr");
		pfloatPtrType=pISInterface->FindLSType("floatptr");
		pfloat64PtrType = pISInterface->FindLSType("float64ptr");
		pBytePtrType=pISInterface->FindLSType("byteptr");
		pPoint3fType = pISInterface->FindLSType("point3f");
		pIndexType = pISInterface->FindLSType("index");
		pVectorType = pISInterface->FindLSType("index");
		pMapType = pISInterface->FindLSType("collection");
		pSetType = pISInterface->FindLSType("set");

		// Connect to commonly used Inner Space services
		ConnectServices();

		// Register LavishScript extensions (commands, aliases, data types, objects)
		RegisterCommands();
		RegisterAliases();
		RegisterDataTypes();
		RegisterTopLevelObjects();

		// Register (create) our own services
		RegisterServices();

		// Register any text triggers built into ISXAO
		RegisterTriggers();

		InitializeISXAO();

		printf("ISXAO version %s Loaded",AO_Version);
		return true;
	}

	// Exception handling sample.  Exception handling should at LEAST be used in functions that
	// are suspected of causing user crashes.  This will help users report the crash and hopefully
	// enable the extension developer to locate and fix the crash condition.
	__except(EzCrashFilter(GetExceptionInformation(),"Crash in initialize routine")) 
	{
		TerminateProcess(GetCurrentProcess(),0);
		return 0;
	}
	/* 
	 * EzCrashFilter takes printf-style formatting after the first parameter.  The above
	 * could look something like this:
	__except(EzCrashFilter(GetExceptionInformation(),"Crash in initialize routine (%s:%d)",__FILE__,__LINE__)) 
	{
		TerminateProcess(GetCurrentProcess(),0);
		return 0;
	}
	 * of course, the FILE and LINE macros would be the location of the exception handler, not the
	 * actual crash, but you should get the idea that extra parameters can be used as if EzCrashFilter
	 * was printf.
	 *
	 * EzCrashFilter will automatically produce a crash log (CrashLog.txt) and open it in notepad for
	 * non-breakpoint exceptions (and hopefully the user will report the crash to the extension developer).  
	 * Your exception handler (the part within the {} under __except) should simply terminate the process 
	 * and return from the function as in the sample.  The return will not be hit, but the compiler will 
	 * whine without it because it doesn't automatically know that the function will not return.  
	 */

}

// shutdown sequence
void ISXAO::Shutdown()
{
	ShutdownLogging();

	// Disconnect from services we connected to
	DisconnectServices();

	// Unregister (destroy) services we created
	UnRegisterServices();

	// Remove LavishScript extensions (commands, aliases, data types, objects)
	UnRegisterTopLevelObjects();
	UnRegisterDataTypes();
	UnRegisterAliases();
	UnRegisterCommands();

	printf("ISXAO Unloaded");
}

/*
 * Note that Initialize and Shutdown are the only two REQUIRED functions in your ISXInterface class.
 * All others are for suggested breakdown of routines, and for example purposes.
 */

void ISXAO::RegisterExtension()
{
	// add this extension to, or update this extension's info in, InnerSpace.xml.
	// This accomplishes a few things.  A) The extension can be loaded by name (ISXAO)
	// no matter where it resides on the system.  B) A script or extension can
	// check a repository to determine if there is an update available (and update
	// if necessary)

	unsigned int ExtensionSetGUID=pISInterface->GetExtensionSetGUID("ISXAO");
	if (!ExtensionSetGUID)
	{
		ExtensionSetGUID=pISInterface->CreateExtensionSet("ISXAO");
		if (!ExtensionSetGUID)
			return;
	}
	pISInterface->SetSetting(ExtensionSetGUID,"Filename",ModuleFileName);
	pISInterface->SetSetting(ExtensionSetGUID,"Path",ModulePath);
	pISInterface->SetSetting(ExtensionSetGUID,"Version",AO_Version);
}

void ISXAO::ConnectServices()
{
	// connect to any services.  Here we connect to "Pulse" which receives a
	// message every frame (after the frame is displayed) and "Memory" which
	// wraps "detours" and memory modifications
	hPulseService=pISInterface->ConnectService(this,"Pulse",PulseService);
	hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);

	// The HTTP service handles URL retrieval
	hHTTPService=pISInterface->ConnectService(this,"HTTP",HTTPService);

	// The Triggers service handles trigger-related functions, including the
	// ability to pass text TO the trigger parser, as well as the ability to
	// add triggers.
	hTriggerService=pISInterface->ConnectService(this,"Triggers",TriggerService);

	// The System service provides general system-related services, including
	// a diagnostics message that allows the extension to insert diagnostic
	// information for the "diagnostics" command, and extension crash logs.
	hSystemService=pISInterface->ConnectService(this,"System",SystemService);

	
}
void ISXAO::RegisterCommands()
{
	// add any commands
//	pISInterface->AddCommand("ISXAO",CMD_ISXAO,true,false);
#define COMMAND(name,cmd,parse,hide) pISInterface->AddCommand(name,cmd,parse,hide);
#include "Commands.h"
#undef COMMAND
}

void ISXAO::RegisterAliases()
{
	// add any aliases
}

void ISXAO::RegisterDataTypes()
{
	// add any datatypes
	// pMyType = new MyType;
	// pISInterface->AddLSType(*pMyType);


#define DATATYPE(_class_,_variable_,_inherits_) _variable_ = new _class_; pISInterface->AddLSType(*_variable_); _variable_->SetInheritance(_inherits_);
#include "DataTypeList.h"
#undef DATATYPE
}

void ISXAO::RegisterTopLevelObjects()
{
	// add any Top-Level Objects
	//pISInterface->AddTopLevelObject("ISXAO",TLO_ISXAO);
#define TOPLEVELOBJECT(name,funcname) pISInterface->AddTopLevelObject(name,funcname);
#include "TopLevelObjects.h"
#undef TOPLEVELOBJECT
}



void ISXAO::RegisterServices()
{
	// register any services.  Here we demonstrate a service that does not use a
	// callback
	// set up a 1-way service (broadcast only)
//	hISXAOService=pISInterface->RegisterService(this,"ISXAO Service",0);
	// broadcast a message, which is worthless at this point because nobody will receive it
	// (nobody has had a chance to connect)
//	pISInterface->ServiceBroadcast(this,hISXAOService,ISXSERVICE_MSG+1,0);

#define SERVICE(_name_,_callback_,_variable_) _variable_=pISInterface->RegisterService(this,_name_,_callback_);
#include "Services.h"	
#undef SERVICE
}

void ISXAO::RegisterTriggers()
{
	// add any Triggers
}

void ISXAO::DisconnectServices()
{
	// gracefully disconnect from services
	if (hPulseService)
		pISInterface->DisconnectService(this,hPulseService);
	if (hMemoryService)
	{
		pISInterface->DisconnectService(this,hMemoryService);
		// memory modifications are automatically undone when disconnecting
		// also, since this service accepts messages from clients we should reset our handle to
		// 0 to make sure we dont try to continue using it
		hMemoryService=0; 
	}
	if (hHTTPService)
	{
		pISInterface->DisconnectService(this,hHTTPService);
	}
	if (hTriggerService)
	{
		pISInterface->DisconnectService(this,hTriggerService);
	}
	if (hSystemService)
	{
		pISInterface->DisconnectService(this,hSystemService);
	}
}

void ISXAO::UnRegisterCommands()
{
	// remove commands
//	pISInterface->RemoveCommand("ISXAO");
#define COMMAND(name,cmd,parse,hide) pISInterface->RemoveCommand(name);
#include "Commands.h"
#undef COMMAND
}
void ISXAO::UnRegisterAliases()
{
	// remove aliases
}
void ISXAO::UnRegisterDataTypes()
{
	// remove data types
#define DATATYPE(_class_,_variable_,_inherits_) pISInterface->RemoveLSType(*_variable_); delete _variable_;
#include "DataTypeList.h"
#undef DATATYPE

}
void ISXAO::UnRegisterTopLevelObjects()
{
	// remove Top-Level Objects
//	pISInterface->RemoveTopLevelObject("ISXAO");
#define TOPLEVELOBJECT(name,funcname) pISInterface->RemoveTopLevelObject(name);
#include "TopLevelObjects.h"
#undef TOPLEVELOBJECT
}
void ISXAO::UnRegisterServices()
{
	// shutdown our own services
//	if (hISXAOService)
//		pISInterface->ShutdownService(this,hISXAOService);

#define SERVICE(_name_,_callback_,_variable_) _variable_=pISInterface->ShutdownService(this,_variable_);
#include "Services.h"
#undef SERVICE
}

void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData)
{
	if (MSG==PULSE_PULSE)
	{
		/*
		 * "OnPulse"
		 * This message is received by the extension before each frame is
		 * displayed by the game.  This is the place to put any repeating
		 * tasks.
		 */

		g_pulse_count++;
		/*while (!g_n3message_queue.empty())
		{
			PN3MESSAGEINFO message_info;
			if (g_n3message_queue.try_pop(message_info))
				HandleN3Message(message_info);
		}
		while (!g_group_message_queue.empty())
		{
			PGROUPMESSAGEINFO group_message_info;
			if (g_group_message_queue.try_pop(group_message_info))
				HandleGroupMessage(group_message_info);
		}
		while (!g_private_message_queue.empty())
		{
			PPRIVATEMESSAGEINFO private_message_info;
			if (g_private_message_queue.try_pop(private_message_info))
				HandlePrivateMessage(private_message_info);
		}
		while (!g_vicinity_message_queue.empty())
		{
			PPRIVATEMESSAGEINFO vicinity_message_info;
			if (g_vicinity_message_queue.try_pop(vicinity_message_info))
				HandleVicinityMessage(vicinity_message_info);
		}
		while (!g_system_chat_queue.empty())
		{
			PSYSTEMCHATINFO system_chat_info;
			if (g_system_chat_queue.try_pop(system_chat_info))
				HandleSystemChat(system_chat_info);
		}*/
	}
}

void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl TriggerService(bool Broadcast, unsigned int MSG, void *lpData)
{
	// no messages are currently associated with this service (other than
	// system messages such as client disconnect), so do nothing.
}

void __cdecl SystemService(bool Broadcast, unsigned int MSG, void *lpData)
{
	if (MSG==SYSTEMSERVICE_DIAGNOSTICS)
	{
		// Diagnostics sample
		/*
		FILE *file=(FILE*)lpData;
		fprintf(file,"ISXAO version %s\n",EXTENSION_VERSION);
		fprintf(file,"------------------------------------\n",EXTENSION_VERSION);
		fprintf(file,"Any ISXAO diagnostic information here\n");
		fprintf(file,"\n");// extra spacing for making the crash log look nice
		/**/
	}
}

void __cdecl HTTPService(bool Broadcast, unsigned int MSG, void *lpData)
{
	switch(MSG)
	{
#define pReq ((HttpFile*)lpData)
	case HTTPSERVICE_FAILURE:
		// HTTP request failed to retrieve document
		printf("ISXAO URL %s failed",pReq->URL);
		break;
	case HTTPSERVICE_SUCCESS:
		// HTTP request successfully retrieved document
		printf("ISXAO URL %s -- %d bytes",pReq->URL,pReq->Size);
		// Retrieved data buffer is pReq->pBuffer and is null-terminated
		break;
#undef pReq
	}
}

void ISXAO::SetExceptionSilentExit(bool bExit)
{
	bExceptionSilentExit = bExit;
}

void ISXAO::ExceptionMessage(const char * pszFormatString, ...)
{
	char szBuffer[1024] = { 0 };
	va_list args;
	va_start(args, pszFormatString);
	vsnprintf_s(szBuffer, sizeof(szBuffer), _TRUNCATE, pszFormatString, args);
	va_end(args);

	FILE * pFile = 0;
	if (fopen_s(&pFile, gp_isxao_log->GetBaseDirFile("ISXAO_Crashlog.txt").c_str(), "a+") == 0)
	{
		if (!pFile)
			return;

		SYSTEMTIME sTime;
		GetLocalTime(&sTime);

		char szDate[64] = { 0 };
		GetDateFormatA(LOCALE_USER_DEFAULT, 0, &sTime, "yyyy'-'MM'-'dd", szDate, 64);

		char szTime[32] = { 0 };
		GetTimeFormatA(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, &sTime, "hh':'mm':'ss", szTime, 32);

		fprintf_s(pFile, "Caught an exception at %s %s\nException info:\n%s\n", szDate, szTime, szBuffer);
		fclose(pFile);
	}
}

int ISXAO::HandleLSTypeCrash(const char * pszFunction, DWORD dwID, void * pObject, int iArgc, char * pszArgv[], DWORD dwCode, _EXCEPTION_POINTERS * pInfo)
{
	std::stringstream sMessage;
	char szMessage[256] = { 0 };

	sprintf_s(szMessage, "Crashed in %s with ID=%i and object=0x%p", pszFunction, dwID, pObject);
	sMessage << szMessage << std::endl;

	if (iArgc)
	{
		sprintf_s(szMessage, "%i argument(s):", iArgc);
		sMessage << szMessage << std::endl;

		for (int i = 0; i < iArgc; ++i)
		{
			sprintf_s(szMessage, "\t%i. %s", i, pszArgv[i]);
			sMessage << szMessage << std::endl;
		}
	}
	else
		sMessage << "0 arguments" << std::endl;

	pExtension->ExceptionMessage(sMessage.str().c_str());

	if (bExceptionSilentExit)
		ExitProcess(0);
	else
		MessageBoxA(0, sMessage.str().c_str(), "WoWX exception", MB_ICONHAND);

	//if( pInfo )
	//	return UnhandledExceptionFilter( pInfo );

	return EXCEPTION_CONTINUE_SEARCH;
}