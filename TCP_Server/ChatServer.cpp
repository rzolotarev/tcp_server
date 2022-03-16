#include "ChatServer.h"
#include "winsock.h"
ChatServer* ChatServer::Start(EventSelector* sel, int port) {
	int ls, res;
	char opt;
	struct sockaddr_in addr;
	ls = socket(AF_INET, SOCK_STREAM, 0);
	if (ls == -1)
		return 0;
	opt = 1;
	setsockopt(ls, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);
	res = bind(ls, (struct sockaddr*) &addr, sizeof(addr));
	if (res == -1)
		return 0;
	res = listen(ls, qlen_for_listen);
	if (res == -1)
		return 0;
	return new ChatServer(sel, ls);
}