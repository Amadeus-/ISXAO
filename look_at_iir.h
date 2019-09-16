#pragma once

class look_at_iir : public info_item_remote
{
public:
	AOLIB_OBJECT look_at_iir(const identity_t*, const identity_t*, int);
private:
	look_at_iir_t look_at_iir_;
};