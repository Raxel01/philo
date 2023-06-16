/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analyse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:41:55 by abait-ta          #+#    #+#             */
/*   Updated: 2023/06/16 11:04:58 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_putstre(char *str)
{
	int	i;

	i = -1;
	write(1, "\033[1;32m", 7);
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
	write(1, "\033[0m\n", 5);
}

long	ft_atoi(char *str)
{
	long	signe;
	long	result;
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	signe = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * signe);
}

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
			ft_putstre("ATTENTION !:don't test with under of 60 \
				ms in this parametres.");
			return (0);
		}
		i++;
	}
	return (1);
}

/*principale parsing fonction*/
int	analyse_data(char **av)
{
	int	i;

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
