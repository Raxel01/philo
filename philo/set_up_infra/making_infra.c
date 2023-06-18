/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_infra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:13:55 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 14:01:15 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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

void	mutex_initializer(t_details_philo *details)
{
	while (details->index < details->number_of_philo)
	{
		pthread_mutex_init(&details->fork[details->index], NULL);
		details->index++;
	}
}

void	add_to_end(t_philo **philo, t_philo *newFilo)
{
	t_philo	*head;

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

t_philo	*new_philo(unsigned int id, t_details_philo *details)
{
	t_philo	*philo;
	
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

void	build_infra_structure(t_philo **philo, t_details_philo *details)
{
	(*philo) = NULL;
	details->index = 1;
	while (details->index <= details->number_of_philo)
	{
		add_to_end(philo, new_philo(details->index, details));
		details->index++;
	}
}
