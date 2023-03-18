/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:30:00 by zjaddad           #+#    #+#             */
/*   Updated: 2023/03/18 16:04:55 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define	PHILO_H

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<limits.h>
#include<sys/time.h>
#include <pthread.h>

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
	int				i;
	int				next;
	int				bolean;
	unsigned long	t_crt;
	unsigned long	t_eat;
	unsigned long	t_slp;
	unsigned long	t_die;
	unsigned long	n_eat;
	unsigned long	last_eat;
	unsigned long	tmp_t;
	pthread_t		philo;
	pthread_mutex_t	*fork;
}	t_philo;

typedef struct p_inf
{
	t_philo	*philo;
	int		n_p;
	int		i;
}	t_p_inf;

int				param_check(char **av);
void			init_struct(t_philo **inf, char **av);
int				init_simulation(t_philo	**inf);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *s);
void			ft_uspleep(unsigned long tm);
unsigned long	get_t(void);

#endif

