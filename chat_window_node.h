#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class chat_window_node
{
public:
	ao::chat_window_node_t get_data() const;
	bool parse_text_command(string&);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::chat_window_node_t chat_window_node_;
};