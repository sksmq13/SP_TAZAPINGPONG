#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>

int set_ticker(int n_msecs) {
	static int counter = 30;
	struct itimerval new_timeset;
	long n_sec, n_usecs;
	n_sec = n_msecs / 1000;
	n_usecs = (n_msecs % 1000) * 1000L;
	new_timeset.it_interval.tv_sec = n_sec;
	new_timeset.it_interval.tv_usec = n_usecs;
	new_timeset.it_value.tv_sec = n_sec;
	new_timeset.it_value.tv_usec = n_usecs;
	
	return setitimer(ITIMER_REAL, &new_timeset, NULL);
}
