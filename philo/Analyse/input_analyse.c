/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analyse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:41:55 by abait-ta          #+#    #+#             */
/*   Updated: 2023/05/29 14:54:03 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	input_state(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_parametres_limits(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[1]) > 200)
		{
			ft_putstre("You have enter more than 200 philo");
			return (0);
		}
		else if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
				|| ft_atoi(av[4]) < 60)
		{
			ft_putstre("ATTENTION ! : don't test with under of 60 ms in this parametres.");
			return (0);
		}
		i++;
	}
	return (1);
}

int	analyse_data(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (input_state(av[i]))
		{
            if (!(check_parametres_limits(av)))
                return (0);
			if (ft_atoi(av[i]) < 0 || ft_atoi(av[i]) > 65535)
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}