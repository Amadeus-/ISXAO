#pragma once

class LookAtIIR : public info_item_remote
{
public:
	AOLIB_OBJECT LookAtIIR(const identity_t*, const identity_t*, int);
private:
	look_at_iir_t look_at_iir_;
};