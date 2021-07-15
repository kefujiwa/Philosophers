/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:47:49 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/07/15 16:25:57 by kefujiwa         ###   ########.fr       */
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

# define FREE 0
# define TAKEN 1

/*
** STRUCTURE
*/

typedef struct s_philo
{
	int				id;
	pthread_t		pthread;
	int				fork;
	int				fork_taken_by;
	pthread_mutex_t	m_fork;
}	t_philo;

typedef struct s_data
{
	int				total;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	t_philo			*philo;
	int				flag;
	pthread_mutex_t	m_flag;
	int				total_finished;
	pthread_mutex_t	m_total_finished;
	pthread_mutex_t	m_write;
}	t_data;

/*
** PROTOTYPE DECLARATION
*/

void	clear_data(t_data *data);
int		puterr_and_return(const char *str);
void	*do_activity(void *d);
long	get_timestamp(void);

int		init_data(t_data *data, int argc, char **argv);
int		init_mutex(t_data *data);
int		init_philo(t_data *data);

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

#endif
