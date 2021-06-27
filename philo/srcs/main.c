/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/06/27 15:19:11 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_data *data)
{
	int		index;
	t_philo	*tmp;

	data->philo = (t_philo*)malloc(sizeof(t_philo) * data->total);
	if (!data->philo)
		return (INVALID);
	index = 0;
	tmp = data->philo;
	while (index < data->total)
	{
		tmp->id = index;
		index++;
		tmp++;
	}
	return (VALID);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) == INVALID)
		return (puterr_and_return("Invalid argument"));
	if (init_philo(&data) == INVALID)
		return (puterr_and_return("Failed to allocate memory"));
}
