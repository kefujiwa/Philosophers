/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:33:16 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/07/17 23:49:40 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*activate_philo(void *philo)
{
	t_philo	*ph;
	int		tm_start_eating;
	int		tm_start_thinking;

	ph = (t_philo *)philo;
	tm_start_eating = get_timestamp();
	if (tm_start_eating < 0)
		return (NULL);
}
