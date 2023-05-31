#include "philo.h"

atomic_int				x = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long	ft_atoi(char *str)
{
	long	signe;
	long	result;
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	signe = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * signe);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
	}
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar((nbr + 48));
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_putstre(char *str)
{
	int	i;

	i = -1;
	write(1, "\033[1;32m", 7);
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
	write(1, "\033[0m\n", 5);
}

// void    leaks(void)
// {
//     system("leaks philo");
// }

// void	*start2(void* arg)
// {
// 	printf("sec thread\n");
// 	(void)arg;
// 	printf("\nHI\n");
// 	if (x >= 20)
// 		x++;
// 	sleep(1);
// 	return (NULL);
// }

// void	*start3(void* arg)
// {
// 	printf("third thread\n");
// 	(void)arg;
// 	x++;
// 	sleep(1);
// 	return (NULL);

// }

void	*philo_task(void *arg)
{
	t_collect_input *philo;
	philo = malloc(sizeof(t_collect_input));

	 philo = (t_collect_input *)(arg);
	printf("===a=c=c=e=s======\n");
	printf("\n================\n");
	for (long i = 0; i < 1; i++)
	{
		printf("first_mutex = %d \n", philo->mutex);
		pthread_mutex_lock(&philo->mutex);
		printf("after_lock_mutex = %d \n",philo->mutex);
		x++;
		pthread_mutex_unlock((pthread_mutex_t *)&philo->mutex);
		printf("final_mutex = %d \n", philo->mutex);
	}
	printf("\n================\n");
	return (NULL);
}

void	creat_threads(t_collect_input *philo, pthread_t thread)
{
	unsigned int	i;
	int				tx;

	i = 0;
	
	
	while (i < philo->number_of_philo)
	{
		tx = pthread_create(&thread, NULL, philo_task, &philo);
		pthread_join(thread, NULL);
		if (tx != 0)
			ft_putstre("error while thread creation");
		i++;
	}
}

void	full_struct(t_collect_input *philo, char **av)
{
	philo->number_of_philo = ft_atoi(av[1]);
	philo->repeat_turn = ft_atoi(av[5]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->mutex = 909;
}

void	print_elem(t_collect_input philo)
{
	if (philo.number_of_philo)
	{
		printf(" philo.number_of_philo = %d \n", philo.number_of_philo);
		printf(" philo->repeat_turn    = %d \n", philo.repeat_turn);
		printf(" philo->time_to_die    = %d \n", philo.time_to_die);
		printf(" philo->time_to_eat    = %d \n", philo.time_to_eat);
		printf(" philo->time_to_sleep  = %d \n", philo.time_to_sleep);
	}
}

int	main(int ac, char **av)
{
	pthread_t thread1, thread2;
	t_collect_input philo;
	pthread_
	
	if (ac == 5 || ac == 6)
	{
		full_struct(&philo, av);
		printf("%d \n", philo.mutex);
		// pthread_mutex_init(&(philo.mutex), NULL);
		if (!analyse_data(av))
		{
			write(1, "by\n", 3);
			return (0);
		}
		creat_threads(&philo, thread1);
		// pthread_mutex_destroy((pthread_mutex_t *)&philo.mutex);
		printf("\n *|x|* = %d \n", x);
	}
	else
		ft_putstre("remember : Enter enough argument");
	return (0);
}