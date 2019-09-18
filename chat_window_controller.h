#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class chat_window_controller
{
public:
	ao::chat_window_controller_t get_chat_window_controller_data() const;
	DWORD get_chat_window_nodes(std::map<string, ao::chat_window_node*>&) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::chat_window_controller_t chat_window_controller_;
}; 