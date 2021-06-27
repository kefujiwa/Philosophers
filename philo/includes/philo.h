/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:47:49 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/06/27 15:55:25 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** EXTERNAL LIBRARIES
*/

# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
** MACRO DECLARATION
*/

# define TYPE_EAT 0
# define TYPE_SLEEP 1
# define TYPE_THINK 2

# define VALID 0
# define INVALID 1

/*
** STRUCTURE
*/

typedef struct s_philo
{
	int	id;
}	t_philo;

typedef struct s_data
{
	int			total;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_must_eat;
	t_philo		*philo;
}	t_data;

/*
** PROTOTYPE DECLARATION
*/

int		init_data(t_data *data, int argc, char **argv);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		puterr_and_return(const char *str);

#endif
