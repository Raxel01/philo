/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:01:27 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/19 17:34:41 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo
{
	pthread_t		philos_th;
	unsigned int	id;
	long long		last_eat;
	struct philo	*next;
	struct collect	*elements;
	unsigned int	left_fork;
	unsigned int	right_fork;
	unsigned int	many_eat;
}					t_philo;

typedef struct collect
{
	unsigned int	index;
	unsigned int	number_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	repeat_turn;
	unsigned int	n_fork;
	long long		time_begin;
	pthread_mutex_t	*fork;
}					t_details_philo;

long long	get_time(void);
long		ft_atoi(char *str);
void		ft_putstre(char *str);
int			analyse_data(char **av);
void		delayer(long long time);
int			thanathos_death(t_philo **philo);
void		mutex_initializer(t_details_philo *details);
void		full_struct(t_details_philo *philo, char **av);
void		ft_lstclear(t_philo **lst, t_details_philo details);
void		generate_thread(t_philo **philo, t_details_philo details);
void		build_infra_structure(t_philo **philo, \
		t_details_philo *details);
#endif