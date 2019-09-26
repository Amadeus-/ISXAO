

#ifndef ISXAO_INTERNAL_H
#define ISXAO_INTERNAL_H

namespace isxao::internal
{
#pragma region SearchDynel

	enum MobileType_e : DWORD
	{
		MOB_NONE = 0,
		MOB_PC = 1,
		MOB_NPC = 2,
		MOB_PET = 3,
		MOB_MYPET = 4,
		MOB_OTHER = 5
	};

	typedef struct _SEARCHACTOR
	{
		DWORD min_level;
		DWORD max_level;
		DWORD actor_type;
		DWORD64 actor_id;
		DWORD64 not_id;
		DWORD from_actor_id;
		FLOAT radius;
		char name[MAX_VARSTRING];
		char breed[MAX_VARSTRING];
		char profession[MAX_VARSTRING];
		BOOL is_healer;
		BOOL is_tank;
		BOOL is_support;
		BOOL is_dps;
		BOOL is_dynel_id;
		DOUBLE y_radius;
		DOUBLE f_radius;
		FLOAT x_loc;
		FLOAT z_loc;
		BOOL is_known_location;
		BOOL no_pets;
		DWORD sort_by;
		BOOL is_exact_name;
	} SEARCHACTOR, *PSEARCHACTOR;

#pragma endregion

#pragma region SearchActor

	//enum ActorType_e
	//{
	//	AT_NONE,
	//	AT_PC,
	//	AT_NPC,
	//	AT_PET,
	//	AT_MYPET,
	//};

	//typedef struct _SEARCHACTOR
	//{
	//	DWORD ActorType;
	//	DWORD MinLevel;
	//	DWORD MaxLevel;
	//	DWORD64 Id;
	//	DWORD64 NotId;
	//	char Profession[MAX_VARSTRING];
	//	char Breed[MAX_VARSTRING];
	//	float MinRadius;
	//	float MaxRadius;
	//	vector3_t Range;
	//	bool KnownLocation;
	//	vector3_t Location;
	//	bool NoPCNear;
	//	float NoPCNearRange;
	//} SEARCHACTOR, *PSEARCHACTOR;


#pragma endregion

#pragma region AOVARPTR

	typedef struct _AOVARPTR
	{
		union {
			struct {
				PVOID Ptr;
				LONG HighPart;
			};
			struct {
				FLOAT Float;
				LONG HighPart;
			};
			struct {
				DWORD DWord;
				LONG HighPart;
			};
			struct {
				DWORD Argb;
				LONG HighPart;
			};
			struct {
				int   Int;
				LONG HighPart;
			};
			struct {
				UCHAR Array[4];
				LONG HighPart;
			};
			struct {
				UCHAR FullArray[8];
			};
			DOUBLE Double;
			__int64   Int64;
			unsigned __int64   UInt64;
		};
	} AOVARPTR, *PAOVARPTR;

#pragma endregion

#pragma region AORank

	typedef struct _AORANK
	{
		AOVARPTR VarPtr;
		AOVARPTR Value;;
	} AORANK, *PAORANK;

	static bool AORankFloatCompare(const AORANK &A, const AORANK &B)
	{
		return A.Value.Float < B.Value.Float;
	}

	static bool pAORankFloatCompare(const PAORANK A, const PAORANK B)
	{
		return A->Value.Float < B->Value.Float;
	}

	static int AORankFloatCompareReverse(const void *A, const void *B)
	{
		if (PAORANK(A)->Value.Float == PAORANK(B)->Value.Float)
			return 0;
		if (PAORANK(A)->Value.Float > PAORANK(B)->Value.Float)
			return -1;
		return -1;
	}

#pragma endregion

#pragma region MessageInfo

	typedef struct _N3MESSAGEINFO
	{
		PVOID message;
		DWORD size;

		_N3MESSAGEINFO(PVOID m, DWORD s)
		{
			message = m;
			size = s;
		}

		~_N3MESSAGEINFO()
		{
			if (message)
				free(message);
		}

	} N3MESSAGEINFO, *PN3MESSAGEINFO;

	typedef struct _GROUPMESSAGEINFO
	{
		ao::identity_t SenderIdentity;
		std::string SenderName;
		std::string ChatChannel;
		std::string Message;

		_GROUPMESSAGEINFO(DWORD sender_id, string& sender_name, string& chat_channel, string& message)
		{
			SenderIdentity.type = 50000;
			SenderIdentity.id = sender_id;
			SenderName = sender_name;
			ChatChannel = chat_channel;
			Message = message;
		}

	} GROUPMESSAGEINFO, *PGROUPMESSAGEINFO;

	typedef struct _PRIVATEMESSAGEINFO
	{
		ao::identity_t SenderIdentity;
		std::string SenderName;
		std::string Message;

		_PRIVATEMESSAGEINFO(DWORD sender_id, std::string& sender_name, std::string& message)
		{
			SenderIdentity.type = 50000;
			SenderIdentity.id = sender_id;
			SenderName = sender_name;
			Message = message;
		}

	} PRIVATEMESSAGEINFO, *PPRIVATEMESSAGEINFO;

	typedef struct _SYSTEMCHATINFO
	{
		DWORD ChatType;
		std::string Text;

		_SYSTEMCHATINFO(DWORD chat_type, std::string* text)
		{
			ChatType = chat_type;
			Text = *text;
		}

	} SYSTEMCHATINFO, *PSYSTEMCHATINFO;

#pragma endregion

}

#endif // ISXAO_INTERNAL_H
