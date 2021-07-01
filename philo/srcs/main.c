/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/07/01 19:23:02 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) == INVALID)
		return (puterr_and_return("Invalid argument"));
	if (init_philo(&data) == INVALID)
		return (puterr_and_return("Failed to allocate memory"));
	if (init_mutex(&data) == INVALID)
	{
		free(data.philo);
		return (puterr_and_return("Failed to initialize mutex"));
	}
}
