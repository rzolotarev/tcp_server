#pragma once
#include "FdHandler.h"

class EventSelector
{
	FdHandler** fd_array;
	int fd_array_len;
	int max_fd;
	bool quit_flag;
public:
	EventSelector(): fd_array(0), quit_flag(false) {}
	~EventSelector();
	void BreKLoop() { quit_flag = true; }
	void Add(FdHandler* h);
	bool Remove(FdHandler* h);
	void Run();
};