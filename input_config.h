#pragma once

class input_config
{
public:
	void set_current_target(const ao::identity_t&);
	static PCSTR get_method_id_name(DWORD);
	static PCSTR get_mode_id_name(DWORD);
	char process_input(ao::keypress_info_t, DWORD);
};