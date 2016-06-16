#pragma once

class Message
{
public:
	AOLIB_OBJECT DWORD DataBlockSizeGet();
	AOLIB_OBJECT DWORD DestIdGet() const;
	AOLIB_OBJECT PVOID GetData();
	AOLIB_OBJECT MESSAGE GetMessageData() const;
	AOLIB_OBJECT static DWORD HeaderSize(DWORD);
	AOLIB_OBJECT DWORD MessageSizeGet(void);
	AOLIB_OBJECT DWORD MessageTypeGet(void) const;
	AOLIB_OBJECT DWORD PriorityGet(void) const;
	AOLIB_OBJECT DWORD SourceIdGet(void) const;
private:
	MESSAGE message_;
};