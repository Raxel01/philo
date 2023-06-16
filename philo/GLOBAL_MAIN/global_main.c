#include "../header/philo.h"









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
		mutex_initializer(details);
		build_infra_structure(&philo, details);
		generate_thread(&philo, *details);
		thanthos_death(&philo);
		sleep(2);
		free(details->fork);
		free(details);
		ft_lstclear(&philo, *(details));
	}
	else
		ft_putstre("Remember : enter anough arguments");
	return (0);
}
