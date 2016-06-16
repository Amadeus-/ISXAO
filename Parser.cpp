#include "isxao_main.h"

namespace isxao_classes
{
	
	Parser::Parser(char* memory, unsigned int size)
		: start_(memory)
		, end_(memory + size)
		, pos_(memory)
	{
	}

	Parser::~Parser()
	{
	}

	DWORD Parser::BytesRemaining() const
	{
		if (end_ > start_) {
			return static_cast<DWORD>(end_ - pos_);
		}
		return 0;
	}

	void Parser::Skip(DWORD count) const
	{
		assert(count <= remaining());

		if (count <= BytesRemaining()) {
			pos_ += count;
		}
	}

	BYTE Parser::PopChar() const
	{
		return *(pos_++);
	}

	WORD Parser::PopShort() const
	{
		unsigned short retval = 0;
		memcpy(&retval, pos_, 2);
		pos_ += 2;
		return _byteswap_ushort(retval);
	}

	DWORD Parser::PopInteger() const
	{
		unsigned int retval = 0;
		memcpy(&retval, pos_, 4);
		pos_ += 4;
		return _byteswap_ulong(retval);
	}

	std::string Parser::PopString() const
	{
		unsigned short len = PopChar();
		std::string retval(pos_, len);
		pos_ += len + 1;
		return retval;
	}

	DWORD Parser::Pop3F1Count() const
	{
		unsigned int val = PopInteger();
		return (val / 1009) - 1;
	}

	SerializedIdentity::SerializedIdentity()
		: type_(0)
		, id_(0)
	{

	}

	SerializedIdentity::SerializedIdentity(Parser &p)
	{
		type_ = p.PopInteger();
		id_ = p.PopInteger();
	}

	N3Header::N3Header(Parser &p)
	{
		n3_type_ = p.PopInteger();				// 0x00
		identity_ = SerializedIdentity(p);		// 0x04
		unknown0xC_ = p.PopChar();				// 0x0C
	}

	AddPetMessage::AddPetMessage(Parser &p)
	{
		pet_id_ = SerializedIdentity(p);
	}

	AttackMessage::AttackMessage(Parser &p)
	{
		target_ = SerializedIdentity(p);
		unknown_ = p.PopChar();
	}

	CastNanoSpellMessage::CastNanoSpellMessage(Parser &p)
	{
		nano_id_ = p.PopInteger();
		target_ = SerializedIdentity(p);
		unknown0xC_ = p.PopInteger();
		caster_ = SerializedIdentity(p);
	}

	CharacterActionMessage::CharacterActionMessage(Parser& p)
	{
		character_action_type = p.PopInteger();
		unknown0x4_ = p.PopInteger();
		identity_ = SerializedIdentity(p);
		param1_ = p.PopInteger();
		param2_ = p.PopInteger();
		param3_ = p.PopShort();
	}

	FollowTargetMessage::FollowTargetMessage(Parser &p)
	{
		p.Skip(2);
		target_ = SerializedIdentity(p);
		p.Skip(17);
	}

	RemovePetMessage::RemovePetMessage(Parser& p)
	{
		pet_id_ = SerializedIdentity(p);
	}

	ShieldAttackMessage::ShieldAttackMessage(Parser& p)
	{
		damage_shielded_ = DWORD(p.PopInteger());
		shieldee_ = SerializedIdentity(p);
		Unknown0x19 = p.PopInteger();
	}

	SpecialAttackWeaponMessage::SpecialAttackWeaponMessage(Parser& p)
	{
		m_Unknown1 = p.PopInteger();
		m_Unknown2 = p.PopInteger();
		m_Unknown3 = p.PopInteger();
		m_Unknown4 = p.PopInteger();
		m_Unknown5 = p.PopInteger();
		m_Unknown6 = p.PopInteger();
		m_Unknown7 = p.PopInteger();
		m_Unknown8 = p.PopInteger();
		m_Unknown9 = p.PopInteger();
		m_Unknown10 = p.PopInteger();
		m_Unknown11 = p.PopInteger();
		m_Unknown12 = p.PopInteger();
		m_Unknown13 = p.PopInteger();
		m_Unknown14 = p.PopInteger();
		m_Unknown15 = p.PopInteger();
		m_Unknown16 = p.PopInteger();
		m_Unknown17 = p.PopInteger();
		m_nAggDef = p.PopInteger();
	}

}

