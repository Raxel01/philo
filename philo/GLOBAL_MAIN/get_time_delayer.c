/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_delayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:08:23 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/20 18:33:40 by abait-ta         ###   ########.fr       */
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

void	delayer(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

void	leaks(void)
{
	system("leaks philo");
}
