/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation_manipulation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:58:37 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 18:23:48 by abait-ta         ###   ########.fr       */
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

int	check_turn(t_philo *node)
{
	t_philo			*check;
	unsigned int	verifier;

	verifier = 1;
	check = node;
	check->elements->index = 0;
	while (check->elements->index < check->elements->number_of_philo)
	{
		if (check->many_eat >= node->elements->repeat_turn)
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
	t_philo			*node;

	node = (*philo);
	node->elements->index = 0;
	while (1)
	{
		if (get_time() - node->last_eat >= node->elements->time_to_die)
		{
			printf("\033[0;33m %lld %d DIED\033[0m\n",
					get_time() - node->elements->time_begin,
					node->id);
			return (0);
		}
		if (node->elements->repeat_turn > 0)
		{
			if (!(check_turn(*philo)))
			{
				printf("\033[0;33m PHILOSOPHER EAT ENOUGH TURNS \033[0m\n");
				return (0);
			}
		}
		node = node->next;
	}
	return (1);
}

void	notification(char c, unsigned int id, long time_begin)
{
	long	time;

	time = get_time();
	time -= time_begin;
	if (c == 'F')
		printf("%ld  %u   has taken a fork\n", time, id);
	if (c == 'e')
		printf("%ld  %u    start    eating\n", time, id);
	if (c == 's')
		printf("%ld  %u   start   sleeping\n", time, id);
	if (c == 't')
		printf("%ld  %u   start   thinking\n", time, id);
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
		notification('F', philo->id, philo->elements->time_begin);
		pthread_mutex_lock(&philo->elements->fork[philo->right_fork]);
		notification('F', philo->id, philo->elements->time_begin);
		notification('e', philo->id, philo->elements->time_begin);
		philo->last_eat = get_time();
		usleep(philo->elements->time_to_eat * 1000);
		philo->many_eat++;
		pthread_mutex_unlock(&philo->elements->fork[(philo->left_fork)]);
		pthread_mutex_unlock(&philo->elements->fork[philo->right_fork]);
		notification('s', philo->id, philo->elements->time_begin);
		usleep(philo->elements->time_to_sleep * 1000);
		notification('t', philo->id, philo->elements->time_begin);
	}
	return (NULL);
}

void	generate_thread(t_philo **philo, t_details_philo details)
{
	t_philo *catcher;
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