#include "philo.h"

long long	x = 0;
pthread_mutex_t mutex;

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

void	*philo_task(void *arg)
{
	t_philo philo = *(t_philo *) arg;
	if (philo.id & 1)
		usleep(600);
	// philo.elements = malloc(sizeof(struct collect));
	printf("philo . %d \n",(philo.elements->number_of_philo));
	// pthread_mutex_lock(&it->mutex);
	write(1, "Hello I'm Here now\n", 20);
	// pthread_mutex_unlock(&(it->mutex));
	return (NULL);
}

void	creat_threads(t_details_philo *philo, pthread_t thread, void *arg)
{
	unsigned int	i;
	int				tx;

	i = 0;
	while (i < philo->number_of_philo)
	{
		tx = pthread_create(&thread, NULL, philo_task, arg);
		pthread_join(thread, NULL);
		if (tx != 0)
			ft_putstre("error while thread creation");
		i++;
	}
}

void	full_struct(t_details_philo *philo, char **av)
{
	philo->number_of_philo = ft_atoi(av[1]);
	philo->repeat_turn = ft_atoi(av[5]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->n_fork = ft_atoi(av[1]);
}


void	print_elem(t_details_philo philo)
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

t_philo	*add_to_end(t_philo *philo, int id)
{
	t_philo	*ptr;
	t_philo	*x;

	ptr = philo;
	x = (t_philo *)malloc(sizeof(t_philo));
	x->id = id;
	x->next = NULL;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = x;
	return (x);
}

void freeall(t_philo **philo)
{
	int Philos = (*philo)->elements->number_of_philo;
	printf("\nZEEB\n");
	printf("here : %u \n", (*philo)->elements->number_of_philo);
	t_philo *catcher; 
	catcher = (*philo);
	for(int i = 0; i < Philos; i++)
	{
			free((catcher));
			(catcher )= (catcher)->next;		
	}
}


void	build_infra_structur(t_philo **philo, t_details_philo details)
{
	t_philo *catcher;
	*(philo) = (t_philo *)malloc(sizeof(philo));
	(*philo)->id = 1;
	(*philo)->elements = malloc(sizeof(struct collect));
	(*philo)->elements = &details;
	(*philo)->next = NULL;
	(*philo)->philos = malloc(sizeof(pthread_t) * details.number_of_philo);
	details.index = 1;
	catcher = *(philo);
	while (details.index <= details.number_of_philo)
	{
		pthread_create(&((*philo)->philos[details.index]), NULL, philo_task, (*philo));
		catcher = add_to_end(*(philo), details.index + 1);
		details.index++;
	}
	details.index = 1;
	while (details.index <= details.number_of_philo)
	{
		pthread_join((*philo)->philos[details.index], NULL);
		details.index++;
	}
	catcher->next = (*philo);
	freeall(&catcher);
}

void	init_mutexes(pthread_mutex_t  *arr, t_details_philo details)
{
	details.index = 1;
	while (details.index <= details.number_of_philo)
	{
		pthread_mutex_init(&arr[details.index], NULL);
		details.index++;
	}
}

int	_main(int ac, char **av)
{
	t_philo *philo;
	t_details_philo details;
	// t_mutex mutex;
	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!(analyse_data(av)))
			return (0);
		full_struct(&details, av);
		details.fork = malloc(sizeof (unsigned int ) * details.number_of_philo);
		init_mutexes(details.fork, details);
		build_infra_structur(&philo, details);
		free(philo->philos);
		free(details.fork);
		free(philo);

		// print_elem(details);
		// philo = malloc(sizeof(t_philo) * details.number_of_philo);
		// details.fork = malloc(sizeof(t_details_philo) * details.n_fork);
		// details.index = 1;
		// while (details.index <= details.number_of_philo)
		// {
		// 	pthread_create((pthread_t *)&philo[details.index],NULL, philo_task, (void *)&mutex);
		// 	details.index++;
		// }	
	}
	else
		ft_putstre("Remember : enter anough arguments");
	return (0);
}

int main(int ac, char **av)
{
	_main(ac, av);
	system("leaks philo");
}