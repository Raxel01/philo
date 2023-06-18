#include "../header/philo.h"

void	print_elems(t_philo *philo)
{
	t_philo			*head;
	unsigned int	i;

	head = philo;
	i = 0;
	while (head && i < philo->elements->number_of_philo + 2)
	{
		// if (i == philo->elements->number_of_philo - 1)
		// {
		// 	printf("||%d|| \n", head->next->id);
		// }
		printf("\e[0;34m id from main = %u \033[0m\n", head->id);
		printf("=======================================\n");
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

int	main(int ac, char **av)
{
	t_philo *philo;
	t_details_philo *details;

	// atexit(leaks);
	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!(analyse_data(av)))
			return (0);
		details = malloc(sizeof(t_details_philo));
		full_struct(details, av);
		details->fork = malloc(sizeof(pthread_mutex_t) * details->number_of_philo);
		mutex_initializer(details);
		build_infra_structure(&philo, details);
		generate_thread(&philo, *details);
		if (!(thanathos_death(&philo)))
			return (0);
	}
	else
		ft_putstre("Remember : enter anough arguments");
	return (0);
}
