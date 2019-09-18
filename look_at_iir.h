#pragma once

class look_at_iir : public ao::info_item_remote
{
public:
	look_at_iir(const ao::identity_t*, const ao::identity_t*, int);
private:
	ao::look_at_iir_t look_at_iir_;
};