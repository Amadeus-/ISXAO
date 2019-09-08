#pragma once

class CastingData
{
public:
	AOLIB_OBJECT identity_t GetCaster() const;
	AOLIB_OBJECT casting_data_t GetCastingData() const;
	AOLIB_OBJECT DWORD GetNanoId() const;
	AOLIB_OBJECT isxao_classes::NanoItem* GetNanoItem() const;
	AOLIB_OBJECT identity_t GetTarget() const;
private:
	casting_data_t casting_data_;
};