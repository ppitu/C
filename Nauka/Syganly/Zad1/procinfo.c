#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "procinfo.h"

int procinfo(const char* name)
{
	printf("%s, UID: %i, GID: %i, PID: %i, PPID: %i, PGID: %i\n", 
		name,
		(int) getuid(),
		(int) getgid(),
		(int) getpid(),
		(int) getppid(),
		(int) getpgid(0));

	return 0;
}
