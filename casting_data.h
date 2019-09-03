#pragma once

class CastingData
{
public:
	AOLIB_OBJECT identity_t GetCaster() const;
	AOLIB_OBJECT CASTINGDATA GetCastingData() const;
	AOLIB_OBJECT DWORD GetNanoId() const;
	AOLIB_OBJECT NanoItem* GetNanoItem() const;
	AOLIB_OBJECT identity_t GetTarget() const;
private:
	CASTINGDATA casting_data_;
};