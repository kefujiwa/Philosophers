/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/07/01 19:32:14 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data)
{
	int		index;
	t_philo	*tmp;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->total);
	if (!data->philo)
		return (INVALID);
	index = 0;
	tmp = data->philo;
	while (index++ < data->total)
	{
		tmp->id = index;
		tmp->fork = FREE;
		tmp->fork_taken_by = FREE;
		tmp++;
	}
	return (VALID);
}
