/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/07/08 09:19:51 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_activity(t_data *data)
{
	int		index;
	t_philo	*tmp;

	index = 0;
	tmp = data->philo;
	while (index++ < data->total)
	{
		pthread_create(&tmp->pthread, NULL, do_activity, data);
		tmp++;
	}
	index = 0;
	tmp = data->philo;
	while (index++ < data->total)
	{
		pthread_join(&tmp->pthread, NULL);
		tmp++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (init_data(&data, argc, argv) == INVALID)
		return (puterr_and_return("Invalid argument"));
	if (init_philo(&data) == INVALID)
		return (puterr_and_return("Failed to allocate memory"));
	if (init_mutex(&data) == INVALID)
	{
		free(data.philo);
		return (puterr_and_return("Failed to initialize mutex"));
	}
	i = 0;
	start_activity(&data);
	clear_data(&data);
	return (EXIT_SUCCESS);
}
