#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class chat_window_controller
{
public:
	AOLIB_OBJECT chat_window_controller_t get_chat_window_controller_data() const;
	AOLIB_OBJECT DWORD get_chat_window_nodes(std::map<string, chat_window_node*>&) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	chat_window_controller_t chat_window_controller_;
}; 