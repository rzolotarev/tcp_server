#pragma once
class FdHandler
{
	int fd;
	bool own_fd;

public:
	FdHandler(int a_fd, bool a_own_id = true): fd(a_fd), own_fd(a_own_id)  {}
	virtual ~FdHandler();
	virtual void Handle(bool r, bool w) = 0;
	int GetFd() { return fd; }
	virtual bool WantRead() const { return true; }
	virtual bool WantWrite() const { return false; }
};

