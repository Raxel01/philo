#include "./header/philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		time_en_milli;

	gettimeofday(&time, NULL);
	time_en_milli = (time.tv_sec * 1000);
	time_en_milli += (time.tv_usec / 1000);
	return (time_en_milli);
}

int main (int ac, char **av)
{
    long long start; // ms;
    long long end; // ms;
    long long Diff; // ms

    start = get_time();
    usleep(9000);// usec = 10^(-3) ms 
    end = get_time();
    printf("Diff = %lld \n", end - start);
    return (0);

}