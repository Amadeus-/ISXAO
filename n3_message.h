#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_n3_message;

	typedef ao_n3_message n3_message_t, *p_n3_message_t;

	class n3_message : public game_object<n3_message_t>
	{
	public:
		char* duplicate_body();
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
