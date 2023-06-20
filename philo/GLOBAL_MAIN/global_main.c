/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:11:57 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/20 17:00:57 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_details_philo	*details;

	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!(analyse_data(av)))
			return (0);
		details = malloc(sizeof(t_details_philo));
		full_struct(details, av);
		details->fork = malloc(sizeof(pthread_mutex_t) \
				* details->number_of_philo);
		mutex_initializer(details);
		build_infra_structure(&philo, details);
		generate_thread(&philo, *details);
		if (!(thanathos_death(&philo)))
			return (0);
	}
	else
		ft_putstre("Remember : enter anough arguments");
	return (0);
}
