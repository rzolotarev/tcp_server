#include <winsock.h>
#include "FdHandler.h"
FdHandler::~FdHandler() {
	if (own_fd) {
		closesocket(fd);
	}
}