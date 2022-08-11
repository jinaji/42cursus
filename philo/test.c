#include "philo.h"

int	main(void)
{
	struct timeval		st_time;
	struct timeval		en_time;		
	long		diff_sec;

	gettimeofday(&st_time, 0);
	gettimeofday(&en_time, 0);
	diff_sec = en_time.tv_usec - st_time.tv_usec;
	printf ("%ld\n", diff_sec);

	printf("%ld\n%d\n", st_time.tv_sec, st_time.tv_usec);
	long usec = st_time.tv_sec * 1000 + st_time.tv_usec / 1000;
	printf ("%ld\n", usec);
}
