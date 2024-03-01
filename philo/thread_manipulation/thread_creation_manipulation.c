/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation_manipulation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:58:37 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/21 15:02:33 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	notification(char c, t_philo *philo, long time_begin)
{
	long	time;

	time = get_time() - time_begin;
	pthread_mutex_lock(&philo->elements->m_die);
	if (c == 'G' || c == 'd')
	{
		usleep(500);
		if (c == 'd')
			printf("\033[0;33m %ld %d DIED\033[0m\n", time, philo->id);
		else
			printf("\033[0;33m PHILOSOPHER EAT %u TIMES \033[0m\n",
				philo->elements->repeat_turn);
	}
	else
	{
		pthread_mutex_unlock(&philo->elements->m_die);
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

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->elements->fork[philo->right_fork]);
	notification('F', philo, philo->elements->time_begin);
	pthread_mutex_lock(&philo->elements->fork[philo->left_fork]);
	notification('F', philo, philo->elements->time_begin);
	notification('e', philo, philo->elements->time_begin);
	pthread_mutex_lock(&philo->elements->m_last_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->elements->m_last_eat);
	delayer(philo->elements->time_to_eat);
	pthread_mutex_lock(&philo->elements->m_many_eat);
	philo->many_eat++;
	pthread_mutex_unlock(&philo->elements->m_many_eat);
	pthread_mutex_unlock(&philo->elements->fork[(philo->left_fork)]);
	pthread_mutex_unlock(&philo->elements->fork[philo->right_fork]);
}

void	*philo_task(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
		usleep(800);
	while (1)
	{
		eat_routine(philo);
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
