#pragma once
namespace std
{
	// class string;
}

namespace isxao
{
	class isxao_message_parser
	{
	public:
		isxao_message_parser(char* memory, unsigned int size);
		isxao_message_parser(isxao_message_parser& other);
		isxao_message_parser(isxao_message_parser&& other) noexcept;
		~isxao_message_parser();

		isxao_message_parser& operator=(const isxao_message_parser& other);
		isxao_message_parser& operator=(isxao_message_parser&& other) noexcept;

		// Number of unsigned chars remaining to be parsed
		unsigned long bytes_remaining() const;

		// Moves the current position the number of unsigned chars ahead
		void skip(unsigned long count) const;

		// Get the next unsigned char
		unsigned char pop_char() const;

		// Get the next 2 unsigned chars 
		short pop_short() const;

		// Get the next 4 unsigned chars
		unsigned long pop_integer() const;

		// Get the string at current position. <len><char[]><NULL>
		std::string pop_string() const;

		// Get the 3F1 encoded counter value 
		// counter = (x/1009)-1
		// ReSharper disable once CppInconsistentNaming
		unsigned long pop_3f1_count() const;

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
		serialized_identity(isxao_message_parser &p);
		unsigned long type() const
		{
			return type_;
		}
		unsigned long id() const
		{
			return id_;
		}
		unsigned long long combined_identity() const
		{
			return (static_cast<unsigned long long>(type_) << 32) | id_;
		}
	private:
		unsigned long type_;
		unsigned long id_;
	};

	class n3_header
	{
	public:
		n3_header(isxao_message_parser &p);
		unsigned long n3_type() const
		{
			return n3_type_;
		}
		serialized_identity identity() const
		{
			return identity_;
		}
		unsigned char unknown_0xC() const
		{
			return unknown0xC_;
		}
	private:
		unsigned long n3_type_;
		serialized_identity identity_;
		unsigned char unknown0xC_;
	};

	class add_pet_message
	{
	public:
		add_pet_message(isxao_message_parser &p);
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
		attack_message(isxao_message_parser &p);
		serialized_identity target() const
		{
			return target_;
		}
	private:
		serialized_identity target_;
		unsigned char unknown_;
	};

	class cast_nano_spell_message
	{
	public:
		cast_nano_spell_message(isxao_message_parser &p);
		unsigned long nano_id() const
		{
			return nano_id_;
		}
		serialized_identity target() const
		{
			return target_;
		}
		unsigned long unknown_0xC() const
		{
			return unknown0xC_;
		}
		serialized_identity caster() const
		{
			return caster_;
		}
	private:
		unsigned long nano_id_;
		serialized_identity target_;
		unsigned long unknown0xC_;
		serialized_identity caster_;
	};

	class character_action_message
	{
	public:
		character_action_message(isxao_message_parser &p);
		unsigned long character_action_type() const
		{
			return character_action_type_;
		}
		serialized_identity identity() const
		{
			return identity_;
		}
		unsigned long param_1() const
		{
			return param1_;
		}
		unsigned long param_2() const
		{
			return param2_;
		}
		unsigned long unknown_0x4() const
		{
			return unknown0x4_;
		}
		short param_3() const
		{
			return param3_;
		}
	private:
		unsigned long character_action_type_;
		unsigned long unknown0x4_;
		serialized_identity identity_;
		unsigned long param1_;
		unsigned long param2_;
		short param3_;
	};

	class follow_target_message
	{
	public:
		follow_target_message(isxao_message_parser &p);
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
		remove_pet_message(isxao_message_parser &p);
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
		shield_attack_message(isxao_message_parser &p);
		unsigned long damage_shielded() const
		{
			return damage_shielded_;
		}
		serialized_identity shieldee() const
		{
			return shieldee_;
		}
	private:
		unsigned long damage_shielded_;
		serialized_identity shieldee_;
		int unknown_0x19;
	};

	class special_attack_weapon_message
	{
	public:
		special_attack_weapon_message(isxao_message_parser &p);
		unsigned long m_Unknown1;
		unsigned long m_Unknown2;
		unsigned long m_Unknown3;
		unsigned long m_Unknown4;
		unsigned long m_Unknown5;
		unsigned long m_Unknown6;
		unsigned long m_Unknown7;
		unsigned long m_Unknown8;
		unsigned long m_Unknown9;
		unsigned long m_Unknown10;
		unsigned long m_Unknown11;
		unsigned long m_Unknown12;
		unsigned long m_Unknown13;
		unsigned long m_Unknown14;
		unsigned long m_Unknown15;
		unsigned long m_Unknown16;
		unsigned long m_Unknown17;
		long m_nAggDef;
	};
}