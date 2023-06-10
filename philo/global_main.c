#include "philo.h"

long long		x = 0;
pthread_mutex_t	mutex[200];

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

long long	get_time(void)
{
	struct timeval	time;
	long long			time_en_milli;

	gettimeofday(&time, NULL);
	time_en_milli = (time.tv_sec * 1000);
	time_en_milli += (time.tv_usec / 1000);
	return (time_en_milli);
}

void	notification(char c, int id, long last_eat)
{
	long	time;

	time = get_time();
	time -= last_eat;
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
		printf("%d \n", philo.elements->time_to_eat);
		// pthread_mutex_lock(&mutex[philo.left_fork]);
		// notification('F', philo.id, philo.last_eat);
		// pthread_mutex_lock(&mutex[philo.right_fork]);
		// notification('F', philo.id, philo.last_eat);
		// philo.last_eat = get_time();
		// notification('e', philo.id, philo.last_eat);
		// philo.many_eat++;
		// usleep(philo.elements->time_to_eat);
		// pthread_mutex_unlock(&mutex[(philo.left_fork)]);
		// pthread_mutex_unlock(&mutex[philo.right_fork]);
		// notification('s', philo.id, philo.last_eat);
		// usleep(philo.elements->time_to_sleep);
		// notification('t', philo.id, philo.last_eat);
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

// t_philo	*creat_first_noeud(t_philo **philo, t_details_philo details)
// {
// 	return ((*philo));
// }

void	add_to_end(t_philo *philo, int id, t_details_philo *details)
{
	t_philo	*ptr;
	t_philo	*x;

	ptr = philo;
	x = (t_philo *)malloc(sizeof(t_philo));
	x->id = id;
	x->left_fork = id;
	x->right_fork = (id + 1) % (details->number_of_philo);
	x->elements = details;
	// printf("%p \n",x->elements);
	if (id == (int)details->number_of_philo)
		x->next = philo;
	else
		x->next = NULL;
	x->many_eat = 0;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = x;
}

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

void	build_infra_structur(t_philo **philo, t_details_philo details)
{
	(*philo) = (t_philo *)malloc(sizeof(philo));
	(*philo)->id = 1;
	(*philo)->left_fork = 1;
	(*philo)->right_fork = 2;
	(*philo)->elements = malloc(sizeof(t_details_philo));
	(*philo)->elements = &details;
	if (details.number_of_philo == 1)
		(*philo)->next = (*philo);
	else
		(*philo)->next = NULL;
	if (details.number_of_philo > 1)
	{
		details.index = 2;
		while (details.index <= details.number_of_philo)
		{
			add_to_end((*philo), details.index, &details);
			details.index++;
		}
	}
			// free_all(philo, details);
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
	}
	*lst = NULL;
}

void	generate_thread(t_philo **philo, t_details_philo details)
{
	t_philo *catcher;

	catcher = (*philo);
	details.index = 0;
	details.time_begin = (long long) get_time;
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
	t_details_philo details;

	// atexit(leaks);
	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!(analyse_data(av)))
			return (0);
		full_struct(&details, av);
		details.fork = malloc(sizeof(unsigned int) * details.number_of_philo);
		while (details.index < details.number_of_philo)
		{
			pthread_mutex_init(&mutex[details.index], NULL);
			details.index++;
		}
		build_infra_structur(&philo, details);
		generate_thread(&philo, details);
		// free(philo);
		free(details.fork);

	}
	else
		ft_putstre("Remember : enter anough arguments");
	return (0);
}