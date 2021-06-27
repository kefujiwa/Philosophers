/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 00:53:51 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/06/27 15:26:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_numeric(char *argv)
{
	while (*argv)
	{
		if (*argv < '0' || *argv > '9')
			return (INVALID);
		argv++;
	}
	return (VALID);
}

static int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (INVALID);
	i = 0;
	while (argv[i])
	{
		if (!is_numeric(*argv))
			return (INVALID);
		i++;
	}
	if (ft_atoi(argv[1]) < 2)
		return (INVALID);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (INVALID);
	return (VALID);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (check_args(argc, argv) == INVALID)
		return (INVALID);
	data->total = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	else
		data->times_must_eat = -1;
	return (VALID);
}
