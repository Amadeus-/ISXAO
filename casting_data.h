#pragma once

class CastingData
{
public:
	AOLIB_OBJECT IDENTITY GetCaster() const;
	AOLIB_OBJECT CASTINGDATA GetCastingData() const;
	AOLIB_OBJECT DWORD GetNanoId() const;
	AOLIB_OBJECT NanoItem* GetNanoItem() const;
	AOLIB_OBJECT IDENTITY GetTarget() const;
private:
	CASTINGDATA casting_data_;
};