/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr_and_return.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:30:03 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/06/21 00:53:25 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	puterr_and_return(const char *str)
{
	char	buf[256];

	ft_strlcpy(buf, "Philosophers: ", sizeof(buf));
	ft_strlcat(buf, str, sizeof(buf));
	ft_strlcat(buf, "\n", sizeof(buf));
	write(2, buf, ft_strlen(buf));
	return (EXIT_FAILURE);
}
