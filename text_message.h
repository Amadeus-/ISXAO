#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_message;

	typedef ao_message message_t, *p_message_t;

	class text_message : public game_object<message_t>
	{
	public:
		const char* message_body_get();
		unsigned long message_body_len();
		unsigned long data_block_size_get();
		unsigned long dest_id_get();
		static unsigned long header_size(unsigned long);
		unsigned long message_size_get();
		unsigned long message_type_get();
		unsigned long priority_get();
		unsigned long source_id_get();
	};
}
