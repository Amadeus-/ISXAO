#pragma once

class LookAtIIR : public InfoItemRemote
{
public:
	AOLIB_OBJECT LookAtIIR(const IDENTITY*, const IDENTITY*, int);
private:
	LOOKATIIR look_at_iir_;
};