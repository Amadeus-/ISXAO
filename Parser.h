#pragma once

class parser
{
public:
	parser(char* memory, unsigned int size);
	parser(parser& other);
	parser(parser&& other) noexcept;
	~parser();

	parser& operator=(const parser& other);
	parser& operator=(parser&& other) noexcept;

	// Number of bytes remaining to be parsed
	DWORD bytes_remaining() const;

	// Moves the current position the number of bytes ahead
	void skip(DWORD count) const;

	// Get the next byte
	BYTE pop_char() const;

	// Get the next 2 bytes 
	WORD pop_short() const;

	// Get the next 4 bytes
	DWORD pop_integer() const;

	// Get the string at current position. <len><char[]><NULL>
	string pop_string() const;

	// Get the 3F1 encoded counter value 
	// counter = (x/1009)-1
	// ReSharper disable once CppInconsistentNaming
	DWORD pop_3f1_count() const;

	char* get_start() const;
	void set_start(char* start);
	char* get_end() const;
	void set_end(char* end);
	char* get_pos() const;
	void set_pos(char* pos) const;

private:
	char* start_;
	char* end_;
	mutable char* pos_;
};

class serialized_identity
{
public:
	serialized_identity();
	serialized_identity(parser &p);
	DWORD type() const
	{
		return type_;
	}
	DWORD id() const
	{
		return id_;
	}
	DWORD64 combined_identity() const
	{
		return (static_cast<UINT64>(type_) << 32) | id_;
	}
private:
	DWORD type_;
	DWORD id_;
};

class n3_header
{
public:
	n3_header(parser &p);
	DWORD n3_type() const
	{
		return n3_type_;
	}
	serialized_identity identity() const
	{
		return identity_;
	}
	BYTE unknown_0xC() const
	{
		return unknown0xC_;
	}
private:
	DWORD n3_type_;
	serialized_identity identity_;
	BYTE unknown0xC_;
};

class add_pet_message
{
public:
	add_pet_message(parser &p);
	serialized_identity identity() const
	{
		return pet_id_;
	}
private:
	serialized_identity pet_id_;
};

class attack_message
{
public:
	attack_message(parser &p);
	serialized_identity target() const
	{
		return target_;
	}
private:
	serialized_identity target_;
	BYTE unknown_;
};

class cast_nano_spell_message
{
public:
	cast_nano_spell_message(parser &p);
	DWORD nano_id() const
	{
		return nano_id_;
	}
	serialized_identity target() const
	{
		return target_;
	}
	DWORD unknown_0xC() const
	{
		return unknown0xC_;
	}
	serialized_identity caster() const
	{
		return caster_;
	}
private:
	DWORD nano_id_;
	serialized_identity target_;
	DWORD unknown0xC_;
	serialized_identity caster_;
};

class character_action_message
{
public:
	character_action_message(parser &p);
	DWORD character_action_type() const
	{
		return character_action_type_;
	}
	serialized_identity identity() const
	{
		return identity_;
	}
	DWORD param_1() const
	{
		return param1_;
	}
	DWORD param_2() const
	{
		return param2_;
	}
	DWORD unknown_0x4() const
	{
		return unknown0x4_;
	}
	WORD param_3() const
	{
		return param3_;
	}
private:
	DWORD character_action_type_;
	DWORD unknown0x4_;
	serialized_identity identity_;
	DWORD param1_;
	DWORD param2_;
	WORD param3_;
};

class follow_target_message
{
public:
	follow_target_message(parser &p);
	serialized_identity target() const
	{
		return target_;
	}
private:
	serialized_identity target_;

};

class remove_pet_message
{
public:
	remove_pet_message(parser &p);
	serialized_identity identity() const
	{
		return pet_id_;
	}
private:
	serialized_identity pet_id_;
};

class shield_attack_message
{
public:
	shield_attack_message(parser &p);
	DWORD damage_shielded() const
	{
		return damage_shielded_;
	}
	serialized_identity shieldee() const
	{
		return shieldee_;
	}
private:
	DWORD damage_shielded_;
	serialized_identity shieldee_;
	int unknown_0x19;
};

class special_attack_weapon_message
{
public:
	special_attack_weapon_message(parser &p);
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