/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:08:23 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/20 17:05:12 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_elems(t_philo *philo)
{
	t_philo			*head;
	unsigned int	i;

	head = philo;
	i = 0;
	while (head && i < philo->elements->number_of_philo + 2)
	{
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

void	delayer(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
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
