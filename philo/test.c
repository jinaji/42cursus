#include "philo.h"

int	main(void)
{
	struct timeval		st_time;
	struct timeval		en_time;		
	long		diff_sec;

	gettimeofday(&st_time, 0);
	sleep(1);
	gettimeofday(&en_time, 0);
	diff_sec = en_time.tv_usec - st_time.tv_usec;
	printf ("%ld\n", diff_sec);
}
