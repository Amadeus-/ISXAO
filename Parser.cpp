#include "isxao_main.h"

namespace isxao_classes
{
	
	parser::parser(char* memory, const unsigned int size)
		: start_(memory)
		, end_(memory + size)
		, pos_(memory)
	{
	}

	parser::parser(parser& other)
	{
		this->start_ = nullptr;
		this->end_ = nullptr;
		this->pos_ = nullptr;
		this->set_start(other.get_start());
		this->set_end(other.get_end());
		this->set_pos(other.get_pos());
	}

	parser::parser(parser&& other) noexcept
	{
		this->start_ = std::exchange(other.start_, nullptr);
		this->end_ = std::exchange(other.end_, nullptr);
		this->pos_ = std::exchange(other.pos_, nullptr);
	}

	parser::~parser() = default;

	parser& parser::operator=(const parser& other)
	{
		if (&other == this)
			return *this;
		this->set_start(other.get_start());
		this->set_end(other.get_end());
		this->set_pos(other.get_pos());
		return *this;
	}

	parser& parser::operator=(parser&& other) noexcept
	{
		this->start_ = std::exchange(other.start_, nullptr);
		this->end_ = std::exchange(other.end_, nullptr);
		this->pos_ = std::exchange(other.pos_, nullptr);
		return *this;
	}

	DWORD parser::bytes_remaining() const
	{
		if (end_ > start_) {
			return static_cast<DWORD>(end_ - pos_);
		}
		return 0;
	}

	void parser::skip(DWORD count) const
	{
		assert(count <= remaining());

		if (count <= bytes_remaining()) {
			pos_ += count;
		}
	}

	BYTE parser::pop_char() const
	{
		return *(pos_++);
	}

	WORD parser::pop_short() const
	{
		unsigned short result = 0;
		memcpy(&result, pos_, 2);
		pos_ += 2;
		return _byteswap_ushort(result);
	}

	DWORD parser::pop_integer() const
	{
		unsigned int result = 0;
		memcpy(&result, pos_, 4);
		pos_ += 4;
		return _byteswap_ulong(result);
	}

	std::string parser::pop_string() const
	{
		const unsigned short length = pop_char();
		std::string result(pos_, length);
		pos_ += length + 1;
		return result;
	}

	DWORD parser::pop_3f1_count() const
	{
		const unsigned int value = pop_integer();
		return (value / 1009) - 1;
	}

	char* parser::get_start() const
	{
		return start_;
	}

	void parser::set_start(char* start)
	{
		this->start_ = start;
	}

	char* parser::get_end() const
	{
		return end_;
	}

	void parser::set_end(char* end)
	{
		this->end_ = end;
	}

	char* parser::get_pos() const
	{
		return pos_;
	}

	void parser::set_pos(char* pos) const
	{
		this->pos_ = pos;
	}

	serialized_identity::serialized_identity()
		: type_(0)
		, id_(0)
	{	}

	serialized_identity::serialized_identity(parser &p)
	{
		type_ = p.pop_integer();
		id_ = p.pop_integer();
	}

	n3_header::n3_header(parser &p)
	{
		n3_type_ = p.pop_integer();				// 0x00
		identity_ = serialized_identity(p);		// 0x04
		unknown0xC_ = p.pop_char();				// 0x0C
	}

	add_pet_message::add_pet_message(parser &p)
	{
		pet_id_ = serialized_identity(p);
	}

	attack_message::attack_message(parser &p)
	{
		target_ = serialized_identity(p);
		unknown_ = p.pop_char();
	}

	cast_nano_spell_message::cast_nano_spell_message(parser &p)
	{
		nano_id_ = p.pop_integer();
		target_ = serialized_identity(p);
		unknown0xC_ = p.pop_integer();
		caster_ = serialized_identity(p);
	}

	character_action_message::character_action_message(parser& p)
	{
		character_action_type_ = p.pop_integer();
		unknown0x4_ = p.pop_integer();
		identity_ = serialized_identity(p);
		param1_ = p.pop_integer();
		param2_ = p.pop_integer();
		param3_ = p.pop_short();
	}

	follow_target_message::follow_target_message(parser &p)
	{
		p.skip(2);
		target_ = serialized_identity(p);
		p.skip(17);
	}

	remove_pet_message::remove_pet_message(parser& p)
	{
		pet_id_ = serialized_identity(p);
	}

	shield_attack_message::shield_attack_message(parser& p)
	{
		damage_shielded_ = DWORD(p.pop_integer());
		shieldee_ = serialized_identity(p);
		unknown_0x19 = p.pop_integer();
	}

	special_attack_weapon_message::special_attack_weapon_message(parser& p)
	{
		m_Unknown1 = p.pop_integer();
		m_Unknown2 = p.pop_integer();
		m_Unknown3 = p.pop_integer();
		m_Unknown4 = p.pop_integer();
		m_Unknown5 = p.pop_integer();
		m_Unknown6 = p.pop_integer();
		m_Unknown7 = p.pop_integer();
		m_Unknown8 = p.pop_integer();
		m_Unknown9 = p.pop_integer();
		m_Unknown10 = p.pop_integer();
		m_Unknown11 = p.pop_integer();
		m_Unknown12 = p.pop_integer();
		m_Unknown13 = p.pop_integer();
		m_Unknown14 = p.pop_integer();
		m_Unknown15 = p.pop_integer();
		m_Unknown16 = p.pop_integer();
		m_Unknown17 = p.pop_integer();
		m_nAggDef = p.pop_integer();
	}

}

