/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_and_check_turn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:31:14 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/20 18:56:40 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_turn(t_philo *node)
{
	t_philo			*check;
	unsigned int	verifier;
	unsigned int	many_eat;

	verifier = 1;
	check = node;
	check->elements->index = 0;
	while (check->elements->index < check->elements->number_of_philo)
	{
		pthread_mutex_lock(&node->elements->m_many_eat);
		many_eat = check->many_eat;
		pthread_mutex_unlock(&node->elements->m_many_eat);
		if (many_eat >= node->elements->repeat_turn)
		{
			verifier++;
			if (verifier == node->elements->number_of_philo)
				return (0);
		}
		check->elements->index++;
		check = check->next;
	}
	return (1);
}

int	thanathos_death(t_philo **philo)
{
	t_philo		*node;
	long long	m_last;

	node = (*philo);
	node->elements->index = 0;
	while (1)
	{
		pthread_mutex_lock(&(*philo)->elements->m_last_eat);
		m_last = get_time() - node->last_eat;
		pthread_mutex_unlock(&(*philo)->elements->m_last_eat);
		if (m_last >= node->elements->time_to_die)
			return (notification('d', node, node->elements->time_begin), 0);
		if (node->elements->repeat_turn > 0)
		{
			if (!(check_turn(*philo)))
				return (notification('G', node, 0), 0);
		}
		node = node->next;
	}
	return (1);
}
