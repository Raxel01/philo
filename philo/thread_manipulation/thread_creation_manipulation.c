#include "../header/philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		time_en_milli;

	gettimeofday(&time, NULL);
	time_en_milli = (time.tv_sec * 1000);
	time_en_milli += (time.tv_usec / 1000);
	return (time_en_milli);
}

void 	thanthos_death(t_philo **philo)	
{
	(void)philo;
printf("hi\n");
}

void	notification(char c, int id, long time_begin)
{
	long	time;

	time = get_time();
	time -= time_begin;
	if (c == 'F')
		printf("%lu  %d   has taken a fork\n", time, id);
	if (c == 'e')
		printf("%lu  %d    start    eating\n", time, id);
	if (c == 's')
		printf("%lu  %d   start   sleeping\n", time, id);
	if (c == 't')
		printf("%lu  %d   start   thinking\n", time, id);
}

void	*philo_task(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	if (philo.id & 1)
		usleep(600);
	while (1)
	{
		pthread_mutex_lock(&philo.elements->fork[philo.left_fork]);
		notification('F', philo.id, philo.elements->time_begin);
		pthread_mutex_lock(&philo.elements->fork[philo.right_fork]);
		notification('F', philo.id, philo.elements->time_begin);
		notification('e', philo.id, philo.elements->time_begin);
		philo.last_eat = get_time() - philo.elements->time_begin;
		// printf(" \033[33m %d \033[1;32m%lld \033[0m\n", philo.id, philo.last_eat);
		usleep(philo.elements->time_to_eat * 1000);
		philo.many_eat++;
		pthread_mutex_unlock(&philo.elements->fork[(philo.left_fork)]);
		pthread_mutex_unlock(&philo.elements->fork[philo.right_fork]);
		notification('s', philo.id, philo.elements->time_begin);
		usleep(philo.elements->time_to_sleep * 1000);
		notification('t', philo.id, philo.elements->time_begin);
	}
	return (NULL);
}

void	generate_thread(t_philo **philo, t_details_philo details)
{
	t_philo	*catcher;

	catcher = (*philo);
	details.index = 0;
	catcher->elements->time_begin = get_time();
	while (details.index < details.number_of_philo)
	{
		if (pthread_create(&(catcher)->philos_th, NULL, philo_task, catcher))
		{
			ft_putstre("Error while creating a thread");
			return;
		}
		details.index++;
		catcher = catcher->next;
	}
	catcher = (*philo);
	details.index = 0;
	while (details.index < details.number_of_philo)
	{
		pthread_detach(catcher->philos_th);
		details.index++;
		catcher = catcher->next;
	}
}