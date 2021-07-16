/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:24:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/07/16 23:16:48 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_data(t_data *data)
{
	int		i;
	t_philo	*tmp;

	pthread_mutex_destroy(&data->m_flag);
	pthread_mutex_destroy(&data->m_total_finished);
	pthread_mutex_destroy(&data->m_write);
	i = 0;
	tmp = data->philo;
	while (i++ < data->total)
	{
		pthread_mutex_destroy(&tmp->m_fork);
		tmp++;
	}
	free(data->philo);
}
