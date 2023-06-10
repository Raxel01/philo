#include "philo.h"

long long		x = 0;
pthread_mutex_t	mutex[200];

void free_all(t_philo **philo,t_details_philo options)
{
	options.index = 0;
	while (options.index < options.number_of_philo)
	{
		free((*philo)->elements);
		(*philo) = (*philo)->next;
		options.index++;
	}

}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

long long	get_time(void)
{
	struct timeval	time;
	long long			time_en_milli;

	gettimeofday(&time, NULL);
	time_en_milli = (time.tv_sec * 1000);
	time_en_milli += (time.tv_usec / 1000);
	return (time_en_milli);
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
		philo.last_eat = get_time();
		notification('e', philo.id, philo.elements->time_begin);
		philo.many_eat++;
		usleep(philo.elements->time_to_eat);
		pthread_mutex_unlock(&philo.elements->fork[(philo.left_fork)]);
		pthread_mutex_unlock(&philo.elements->fork[philo.right_fork]);
		notification('s', philo.id,philo.elements->time_begin);
		usleep(philo.elements->time_to_sleep);
		notification('t', philo.id, philo.elements->time_begin);
	}
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
	philo->index = 0;
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

t_philo *new_philo(int id, t_details_philo *details)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	philo->id = id;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % (details->number_of_philo);
	philo->elements = details;
		if (details->number_of_philo == 1)
		philo->next = philo;
	else
		philo->next = NULL;
	return (philo);
}

void	add_to_end(t_philo **philo, t_philo *newFilo)
{
	t_philo *head;

	if (!(*philo))
		(*philo) = newFilo;
	else
	{
		head = *philo;
		if (newFilo->id == newFilo->elements->number_of_philo)
			newFilo->next = *philo;
		else
			newFilo->next = NULL;
		newFilo->many_eat = 0;
		while (head->next)
		{
			head = head->next;
		}
		head->next = newFilo;
	}
}

void	build_infra_structure(t_philo **philo, t_details_philo *details)
{
	details->index = 1;
	(*philo) = NULL;

	while (details->index <= details->number_of_philo)
	{
		add_to_end(philo, new_philo(details->index, details));
		details->index++;
	}	
}

void	print_elems(t_philo *philo)
{
	t_philo			*head;
	unsigned int	i;

	head = philo;
	i = 0;
	while (head && i < philo->elements->number_of_philo)
	{
		if (i == philo->elements->number_of_philo - 1)
		{
			printf("||%d|| \n", head->next->id);
		}
		printf("id = %d | left_fork = %d | right_fork = %d | \n", head->id,
				head->left_fork, head->right_fork);
		i++;
		head = head->next;
	}
}

void	leaks(void)
{
	system("leaks philo");
}

void	ft_lstclear(t_philo **lst, t_details_philo details)
{
	t_philo			*old_node;
	unsigned int	i;

	i = 0;
	if (!*lst)
		return ;
	while (*lst && i < details.number_of_philo)
	{
		old_node = *lst;
		*lst = old_node->next;
		free(old_node);
		i++;
	}
	*lst = NULL;
}

void	generate_thread(t_philo **philo, t_details_philo details)
{
	t_philo *catcher;

	catcher = (*philo);
	details.index = 0;
	catcher->elements->time_begin =  get_time();
	while (details.index < details.number_of_philo)
	{
		if (pthread_create(&(catcher)->philos_th, NULL, philo_task, catcher))
					{
						write(1, "by\n", 3);
						exit(3);
					}
		details.index++;
		catcher = catcher->next;
	}
	catcher = (*philo);
	details.index = 0;
	while (details.index < details.number_of_philo)
	{
		pthread_join(catcher->philos_th, NULL);
		details.index++;
		catcher = catcher->next;

	}

}

int	main(int ac, char **av)
{
	t_philo *philo;
	t_details_philo *details;

	atexit(leaks);
	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!(analyse_data(av)))
			return (0);
		details = malloc(sizeof(t_details_philo));
		full_struct(details, av);
		details->fork = malloc(sizeof(unsigned int) * details->number_of_philo);
		while (details->index < details->number_of_philo)
		{
			pthread_mutex_init(&details->fork[details->index], NULL);
			details->index++;
		}
		build_infra_structure(&philo, details);
		// print_elems(philo);
		// pthread_mutex_destroy()
		generate_thread(&philo, *details);
		// free(philo);
		free(details->fork);
		free(details);
		ft_lstclear(&philo, *(details));
	}
	else
		ft_putstre("Remember : enter anough arguments");
	return (0);
}