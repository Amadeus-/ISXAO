#pragma once
#include <isxdk.h>
#include <windows.h>


class ISXAO :
	public ISXInterface
{
	bool bExceptionSilentExit;
public:
	ISXAO(void);
	~ISXAO(void);

	virtual bool Initialize(ISInterface *p_ISInterface);
	virtual void Shutdown();

	void RegisterExtension();

	void ConnectServices();
	void RegisterCommands();
	void RegisterAliases();
	void RegisterDataTypes();
	void RegisterTopLevelObjects();
	void RegisterServices();
	void RegisterTriggers();

	void DisconnectServices();
	void UnRegisterCommands();
	void UnRegisterAliases();
	void UnRegisterDataTypes();
	void UnRegisterTopLevelObjects();
	void UnRegisterServices();

	void SetExceptionSilentExit(bool bExit);
	void ExceptionMessage(const char * pszFormatString, ...);
	int HandleLSTypeCrash(const char * pszFunction, DWORD dwID, void * pObject, int iArgc, char * pszArgv[], DWORD dwCode = 0, _EXCEPTION_POINTERS * pInfo = 0);
};

extern ISInterface *pISInterface;
extern HISXSERVICE hPulseService;
extern HISXSERVICE hMemoryService;
extern HISXSERVICE hHTTPService;
extern HISXSERVICE hTriggerService;
extern HISXSERVICE hSystemService;

extern ISXAO *pExtension;
#define printf pISInterface->Printf

#define EzDetour(Address, Detour, Trampoline) IS_Detour(pExtension,pISInterface,hMemoryService,(unsigned int)Address,Detour,Trampoline)
#define EzUnDetour(Address) IS_UnDetour(pExtension,pISInterface,hMemoryService,(unsigned int)Address)
#define EzDetourAPI(_Detour_,_DLLName_,_FunctionName_,_FunctionOrdinal_) IS_DetourAPI(pExtension,pISInterface,hMemoryService,_Detour_,_DLLName_,_FunctionName_,_FunctionOrdinal_)
#define EzUnDetourAPI(Address) IS_UnDetourAPI(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzModify(Address,NewData,Length,Reverse) Memory_Modify(pExtension,pISInterface,hMemoryService,(unsigned int)Address,NewData,Length,Reverse)
#define EzUnModify(Address) Memory_UnModify(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzHttpRequest(_URL_,_pData_) IS_HttpRequest(pExtension,pISInterface,hHTTPService,_URL_,_pData_)

#define EzAddTrigger(Text,Callback,pUserData) IS_AddTrigger(pExtension,pISInterface,hTriggerService,Text,Callback,pUserData)
#define EzRemoveTrigger(ID) IS_RemoveTrigger(pExtension,pISInterface,hTriggerService,ID)
#define EzCheckTriggers(Text) IS_CheckTriggers(pExtension,pISInterface,hTriggerService,Text)

static LONG EzCrashFilter(_EXCEPTION_POINTERS *pExceptionInfo,const char *szIdentifier,...)
{
	unsigned int Code=pExceptionInfo->ExceptionRecord->ExceptionCode;
	if (Code==EXCEPTION_BREAKPOINT || Code==EXCEPTION_SINGLE_STEP)
		return EXCEPTION_CONTINUE_SEARCH;

	char szOutput[4096];
	szOutput[0]=0;
    va_list vaList;

    va_start( vaList, szIdentifier );
    vsprintf_s(szOutput,szIdentifier, vaList);

	IS_SystemCrashLog(pExtension,pISInterface,hSystemService,pExceptionInfo,szOutput);

	return EXCEPTION_EXECUTE_HANDLER;
}

extern LSType *pStringType;
extern LSType *pIntType;
extern LSType *pUintType;
extern LSTypeDefinition *pInt64Type;
extern LSTypeDefinition *pInt64PtrType;
extern LSType *pBoolType;
extern LSType *pfloatType;
extern LSType *pTimeType;
extern LSType *pByteType;
extern LSType *pIntPtrType;
extern LSType *pBoolPtrType;
extern LSTypeDefinition *pfloat64PtrType;
extern LSType *pfloatPtrType;
extern LSType *pBytePtrType;
extern LSTypeDefinition *pPoint3fType;
extern LSTypeDefinition *pIndexType;
extern LSTypeDefinition *pVectorType;
extern LSTypeDefinition *pMapType;
extern LSTypeDefinition *pSetType;

#define ReturnDeepObject(val) ENCAPSULATE( Object.Ptr = val; Object.Type = GetRealType(val); )


extern char AO_Version[];

#include "Commands.h"
#include "DataTypes.h"
#include "TopLevelObjects.h"
#include "Services.h"
#include "ISXAOServices.h"
