#include "system_call_overhead.h"

void system_call_overhead() {
    printf("System Calls, 0, 0\n");

    PM(syscall(SYS_gettid), "gettid(), "O_STR);

    PM(getpid(), "getpid(), "O_STR);

    PM(getuid(), "getuid(), "O_STR);

    PM(getppid(), "getppid(), "O_STR);

    int more_trash = 0;
    PM(wait(&more_trash), "wait(&ptr_to_int), "O_STR);


	int fd = open("trashfile.txt",O_WRONLY);
	char* buf = "thequickbrownfoxjumpedoverthelazydog";
    PM(write(fd,buf,sizeof(buf)), "\"write(fd,buf,sizeof(buf))\", "O_STR);
	close(fd);
    unlink("trashfile.txt");

	fd = open("trashfile.txt",O_WRONLY);
    #define WR_SYNC write(fd,buf,sizeof(buf)); sync();
    PM_COUNT(WR_SYNC, "\"write(fd,buf,sizeof(buf));sync();\", "O_STR, 10);
	close(fd);
    unlink("trashfile.txt");

    PM(raise(SIGCHLD), "raise(SIGCHLD), "O_STR);
}
