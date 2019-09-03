#pragma once

class LookAtIIR : public InfoItemRemote
{
public:
	AOLIB_OBJECT LookAtIIR(const identity_t*, const identity_t*, int);
private:
	LOOKATIIR look_at_iir_;
};