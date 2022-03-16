#pragma once
#include "FdHandler.h"
#include "ChatServer.h"
#include "Constants.h"
class ChatSession : FdHandler {
	friend class ChatServer;
	char buffer[max_line_length + 1];
	int buf_used;
	bool ignoring;
	char* name;
	ChatServer* the_master;

	ChatSession(ChatServer* a_master, int fd);
	~ChatSession();
	void Send(const char *msg);
	virtual void Handle(bool r, bool w);
	void ReadAndIgnore();
	void ReadAndCheck();
	void CheckLines();
	void ProcessLines();
};