/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/07/08 09:32:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex_philo(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = data->philo;
	while (i++ < data->total)
	{
		if (pthread_mutex_init(&tmp->m_fork, NULL))
		{
			while (tmp->id > 1)
				pthread_mutex_destroy(&(--tmp)->m_fork);
			return (INVALID);
		}
		tmp++;
	}
	return (VALID);
}

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->m_flag, NULL))
		return (INVALID);
	if (pthread_mutex_init(&data->m_total_finished, NULL))
	{
		pthread_mutex_destroy(&data->m_flag);
		return (INVALID);
	}
	if (pthread_mutex_init(&data->m_write, NULL))
	{
		pthread_mutex_destroy(&data->m_flag);
		pthread_mutex_destroy(&data->m_total_finished);
		return (INVALID);
	}
	if (init_mutex_philo(data) == INVALID)
	{
		pthread_mutex_destroy(&data->m_flag);
		pthread_mutex_destroy(&data->m_total_finished);
		pthread_mutex_destroy(&data->m_write);
		return (INVALID);
	}
	return (VALID);
}
