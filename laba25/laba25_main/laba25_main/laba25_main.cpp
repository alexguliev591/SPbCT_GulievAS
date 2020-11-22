#include <stdio.h>
#include <signal.h>
#include <wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int f_in, pid, N, M;

void stopfn(int n)
{
	close(f_in);
	exit(0);
}

void sigper(int n)
{
	char c, * sig;

	if (n != SIGUSR1 && n != SIGALRM)
		return;

	c = n == SIGUSR1 ? '\0' : '\n';
	sig = n == SIGUSR1 ? (char*)"USR1" : (char*)"ALRM";

	printf("%cSIG%s\n", c, sig);

	while (read(f_in, &c, 1) == 1)
		write(1, &c, 1);

	lseek(f_in, 0, SEEK_SET);
	kill(getppid(), SIGUSR1);
	printf("\n");
}

int main(int argc, char* argv[])
{
	int i = 0;
	ssize_t ret;
	char inp;

	if (argc < 4) {
		printf("error: insuffucient arguments\n");
		return 1;
	}

	if ((f_in = open(argv[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) < 0) {
		printf("Can't open %s\n", argv[1]);
		return 1;
	}
	N = atoi(argv[2]);
	M = atoi(argv[3]);

	if ((pid = fork()) < 0) {
		printf("Can't fork\n");
	}
	else if (pid == 0) {
		signal(SIGUSR1, sigper);
		signal(SIGALRM, sigper);
		alarm(M);
		pause();
	}
	else {
		signal(SIGUSR1, stopfn);
		do {
			ret = read(0, &inp, 1);
			if (inp == '\r' || inp == '\n' || ret <= 0)
				break;
			if (i < N) {
				write(f_in, &inp, 1);
				i++;
			}
		} while (ret > 0);
		lseek(f_in, 0, SEEK_SET);
		kill(pid, SIGUSR1);
	}
	close(f_in);

	return (0);
}