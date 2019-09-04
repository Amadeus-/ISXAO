#pragma once

class NanoTemplate
{
public:
	AOLIB_OBJECT DWORD GetDuration() const;
	AOLIB_OBJECT identity_t GetCasterIdentity() const;
	AOLIB_OBJECT identity_t GetNanoIdentity() const;
	AOLIB_OBJECT nano_template_t GetNanoTemplateData() const;
	AOLIB_OBJECT DWORD GetStartTime() const;
	AOLIB_OBJECT float GetTimeRemaining() const;
	AOLIB_OBJECT static bool NanoTemplateCompare(NanoTemplate &, NanoTemplate &);
	AOLIB_OBJECT bool Remove() const;
private:
	nano_template_t nano_template_;
};