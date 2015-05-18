#include <stdio.h>
#include<signal.h>
#include<unistd.h>

void HandleSignal(int sig, siginfo_t *si, void *context)
{
	switch(sig)
	{
		case SIGINT:
			printf("\nControl-C was pressed: mypid = %u\n",
					si->si_pid);
			_exit(0);
			break;
		case SIGTERM:
			printf("\nStigterm received mypid = %u\n",
					si->si_pid);
			_exit(0);
			break;
	}
}

int main(void)
{
	struct sigaction sVal;
	sVal.sa_flags = SA_SIGINFO;
	sVal.sa_sigaction = HandleSignal;
	sigaction(SIGINT, &sVal, NULL);
	sigaction(SIGTERM, &sVal, NULL);
	// A long long wait so that we can easily issue a signal to this process
	while(1) 
		sleep(1);
	return 0;
}
