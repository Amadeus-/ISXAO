#pragma once

class Parser
{
public:
	Parser(char* memory, unsigned int size);
	~Parser();

	// Number of bytes remaining to be parsed
	DWORD BytesRemaining() const;

	// Moves the current position the number of bytes ahead
	void Skip(DWORD count) const;

	// Get the next byte
	BYTE PopChar() const;

	// Get the next 2 bytes 
	WORD PopShort() const;

	// Get the next 4 bytes
	DWORD PopInteger() const;

	// Get the string at current position. <len><char[]><NULL>
	std::string PopString() const;

	// Get the 3F1 encoded counter value 
	// counter = (x/1009)-1
	DWORD Pop3F1Count() const;

	char* Start() const { return start_; }
	char* End() const { return end_; }
	char* Pos() const { return pos_; }

private:
	char* start_;
	char* end_;
	mutable char* pos_;
};

class SerializedIdentity
{
public:
	SerializedIdentity();
	SerializedIdentity(Parser &p);
	DWORD Type() const
	{
		return type_;
	}
	DWORD Id() const
	{
		return id_;
	}
	DWORD64 CombinedIdentity() const
	{
		return (static_cast<UINT64>(type_) << 32) | id_;
	}
private:
	DWORD type_;
	DWORD id_;
};

class N3Header
{
public:
	N3Header(Parser &p);
	DWORD N3Type() const
	{
		return n3_type_;
	}
	SerializedIdentity Identity() const
	{
		return identity_;
	}
	BYTE Unknown0xC() const
	{
		return unknown0xC_;
	}
private:
	DWORD n3_type_;
	SerializedIdentity identity_;
	BYTE unknown0xC_;
};

class AddPetMessage
{
public:
	AddPetMessage(Parser &p);
	SerializedIdentity Identity() const
	{
		return pet_id_;
	}
private:
	SerializedIdentity pet_id_;
};

class AttackMessage
{
public:
	AttackMessage(Parser &p);
	SerializedIdentity Target() const
	{
		return target_;
	}
private:
	SerializedIdentity target_;
	BYTE unknown_;
};

class CastNanoSpellMessage
{
public:
	CastNanoSpellMessage(Parser &p);
	DWORD NanoId() const
	{
		return nano_id_;
	}
	SerializedIdentity Target() const
	{
		return target_;
	}
	DWORD Unknown0xC() const
	{
		return unknown0xC_;
	}
	SerializedIdentity Caster() const
	{
		return caster_;
	}
private:
	DWORD nano_id_;
	SerializedIdentity target_;
	DWORD unknown0xC_;
	SerializedIdentity caster_;
};

class CharacterActionMessage
{
public:
	CharacterActionMessage(Parser &p);
	DWORD CharacterActionType() const
	{
		return character_action_type;
	}
	SerializedIdentity Identity() const
	{
		return identity_;
	}
	DWORD Param1() const
	{
		return param1_;
	}
	DWORD Param2() const
	{
		return param2_;
	}
	DWORD Unknown0x4() const
	{
		return unknown0x4_;
	}
	WORD Param3() const
	{
		return param3_;
	}
private:
	DWORD character_action_type;
	DWORD unknown0x4_;
	SerializedIdentity identity_;
	DWORD param1_;
	DWORD param2_;
	WORD param3_;
};

class FollowTargetMessage
{
public:
	FollowTargetMessage(Parser &p);
	SerializedIdentity Target() const
	{
		return target_;
	}
private:
	SerializedIdentity target_;

};

class RemovePetMessage
{
public:
	RemovePetMessage(Parser &p);
	SerializedIdentity Identity() const
	{
		return pet_id_;
	}
private:
	SerializedIdentity pet_id_;
};

class ShieldAttackMessage
{
public:
	ShieldAttackMessage(Parser &p);
	DWORD DamageShielded() const
	{
		return damage_shielded_;
	}
	SerializedIdentity Shieldee() const
	{
		return shieldee_;
	}
private:
	DWORD damage_shielded_;
	SerializedIdentity shieldee_;
	int Unknown0x19;
};

class SpecialAttackWeaponMessage
{
public:
	SpecialAttackWeaponMessage(Parser &p);
	DWORD m_Unknown1;
	DWORD m_Unknown2;
	DWORD m_Unknown3;
	DWORD m_Unknown4;
	DWORD m_Unknown5;
	DWORD m_Unknown6;
	DWORD m_Unknown7;
	DWORD m_Unknown8;
	DWORD m_Unknown9;
	DWORD m_Unknown10;
	DWORD m_Unknown11;
	DWORD m_Unknown12;
	DWORD m_Unknown13;
	DWORD m_Unknown14;
	DWORD m_Unknown15;
	DWORD m_Unknown16;
	DWORD m_Unknown17;
	LONG m_nAggDef;
};