/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation_manipulation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:58:37 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/20 17:06:45 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_turn(t_philo *node)
{
	t_philo			*check;
	unsigned int	verifier;
	unsigned int many_eat;

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
	t_philo	*node;
	long long	m_last;

	node = (*philo);
	node->elements->index = 0;
	while (1)
	{
		pthread_mutex_lock(&(*philo)->elements->m_last_eat);
		m_last = get_time() - node->last_eat;
		pthread_mutex_unlock(&(*philo)->elements->m_last_eat);
		if (m_last >= node->elements->time_to_die)
		{
			notification('d', node, node->elements->time_begin);
			return (0);
		}
		if (node->elements->repeat_turn > 0)
		{
			if (!(check_turn(*philo)))
			{
				notification('G', node, 0);	
				return (0);
			}
		}
		node = node->next;
	}
	return (1);
}

void	notification(char c, t_philo *philo, long time_begin)
{
	long	time;

	time = get_time();
	time -= time_begin;
	pthread_mutex_lock(&philo->elements->m_die);
	if (c == 'd')
	{
		printf("\033[0;33m %ld %d DIED\033[0m\n",time, philo->id);
	}
	else
	{
		if (c != 'G')
			pthread_mutex_unlock(&philo->elements->m_die);
		if (c == 'G')
		{
			usleep(500);
			printf("\033[0;33m PHILOSOPHER EAT ENOUGH TURNS \033[0m\n");
		}
		if (c == 'F')
			printf("%ld  %u   has taken a fork\n", time, philo->id);
		if (c == 'e')
			printf("%ld  %u    start    eating\n", time, philo->id);
		if (c == 's')
			printf("%ld  %u   start   sleeping\n", time, philo->id);
		if (c == 't')
			printf("%ld  %u   start   thinking\n", time, philo->id);
	}
}

void	*philo_task(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
		usleep(800);
	while (1)
	{
		pthread_mutex_lock(&philo->elements->fork[philo->left_fork]);
		notification('F', philo, philo->elements->time_begin);
		pthread_mutex_lock(&philo->elements->fork[philo->right_fork]);
		notification('F', philo, philo->elements->time_begin);
		notification('e', philo, philo->elements->time_begin);
		pthread_mutex_lock(&philo->elements->m_last_eat);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->elements->m_last_eat);
		delayer(philo->elements->time_to_eat);
		pthread_mutex_lock(&philo->elements->m_many_eat);
		philo->many_eat++;
		pthread_mutex_unlock(&philo->elements->m_many_eat);
		pthread_mutex_unlock(&philo->elements->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->elements->fork[(philo->left_fork)]);
		notification('s', philo, philo->elements->time_begin);
		delayer(philo->elements->time_to_sleep);
		notification('t', philo, philo->elements->time_begin);
	}
	return (NULL);
}

void	generate_thread(t_philo **philo, t_details_philo details)
{
	t_philo	*catcher;
	int		i;

	i = 0;
	catcher = (*philo);
	catcher->elements->time_begin = get_time();
	while ((unsigned int)i < details.number_of_philo)
	{
		catcher->last_eat = get_time();
		if (pthread_create(&(catcher)->philos_th, NULL, philo_task, catcher))
		{
			ft_putstre("Error while creating a thread");
			return ;
		}
		i++;
		catcher = catcher->next;
	}
}
