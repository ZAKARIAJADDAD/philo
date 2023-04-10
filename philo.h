/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:30:00 by zjaddad           #+#    #+#             */
/*   Updated: 2023/04/10 21:36:21 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include<limits.h>
# include<sys/time.h>
# include <pthread.h>

typedef struct atoi
{
	int		i;
	long	result;
	int		sign;
}	t_ati;

typedef struct philo
{
	struct philo	*phl;
	int				id;
	int				n_p;
	unsigned long	i;
	unsigned long	next;
	unsigned long	bolean;
	unsigned long	situ;
	unsigned long	t_eat;
	unsigned long	t_slp;
	unsigned long	t_die;
	int				n_eat;
	unsigned long	crt_t;
	unsigned long	start_t;
	unsigned long	last_eat;
	unsigned long	tmp_t;
	pthread_t		philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*msg_mutex;
	pthread_mutex_t	lock_mutex;
	pthread_mutex_t	n_eat_mutex;
}	t_philo;

int				param_check(char **av);
int				ft_atoi(const char *s);
int				init_simulation(t_philo	*inf, long start);
int				print_error(int nb);
void			init_struct(t_philo **inf, char **av);
void			ft_usleep(unsigned long tm);
void			*routine(t_philo *inf);
void			show_msg(t_philo *inf, char *s, int time);
size_t			ft_strlen(const char *s);
unsigned long	get_t(void);
void			*ft_memset(void *vp, int c, size_t lent);
void			*pre_routine(void *arg);

#endif
