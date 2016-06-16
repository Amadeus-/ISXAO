#pragma once

class NanoTemplate
{
public:
	AOLIB_OBJECT DWORD GetDuration() const;
	AOLIB_OBJECT IDENTITY GetCasterIdentity() const;
	AOLIB_OBJECT IDENTITY GetNanoIdentity() const;
	AOLIB_OBJECT NANOTEMPLATE GetNanoTemplateData() const;
	AOLIB_OBJECT DWORD GetStartTime() const;
	AOLIB_OBJECT float GetTimeRemaining() const;
	AOLIB_OBJECT static bool NanoTemplateCompare(NanoTemplate &, NanoTemplate &);
	AOLIB_OBJECT bool Remove() const;
private:
	NANOTEMPLATE nano_template_;
};