/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:01:27 by abait-ta          #+#    #+#             */
/*   Updated: 2023/05/29 16:48:24 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
# define PHILO

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
# include <string.h>
# include <pthread.h>
# include <stdatomic.h>


typedef struct philo
{
    int id;
    int count;
    
}   t_philo;
 
typedef struct collect
{    
    unsigned int number_of_philo;
    unsigned int     time_to_die;
    unsigned int     time_to_eat;
    unsigned int   time_to_sleep;
    unsigned int     repeat_turn;
    int                    mutex;
}   t_collect_input;

long     ft_atoi(char *str);
void	 ft_putstre(char *str);
int      analyse_data(char **av);

#endif