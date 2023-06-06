/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:01:27 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/06 22:33:33 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
# define PHILO

# include <pthread.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo
{
	pthread_t		*philos;
	int				id;
	unsigned int    last_eat;
	struct philo 	*next;
	struct collect  *elements;
    unsigned int    many_eat;
}					t_philo;

typedef struct collect
{
	unsigned int 	index;
	unsigned int	number_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	repeat_turn;
	unsigned int 	n_fork;
    pthread_mutex_t	    *fork;
}					t_details_philo;

long				ft_atoi(char *str);
void				ft_putstre(char *str);
int					analyse_data(char **av);

#endif