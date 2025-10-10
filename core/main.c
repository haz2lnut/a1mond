#include "daemon.h"

#include <unistd.h>

#define PID_FILENAME "/var/run/a1mond.pid"

int main() {
	if(daemon_create(PID_FILENAME))
		return 1;

	while(1) pause();
	return 0;
}
