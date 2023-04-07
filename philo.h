/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:30:00 by zjaddad           #+#    #+#             */
/*   Updated: 2023/04/07 03:18:25 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<string.h>
# include<unistd.h>
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
	int				i;
	int				next;
	int				bolean;
	int				situ;
	int				t_eat;
	int				t_slp;
	int				t_die;
	int				n_eat;
	long			crt_t;
	long			start_t;
	long			last_eat;
	long			tmp_t;
	pthread_t		philo;
	pthread_mutex_t	fork;
}	t_philo;

int				param_check(char **av);
int				ft_atoi(const char *s);
int				init_simulation(t_philo	*inf, long start);
int				print_error(int nb);
void			init_struct(t_philo **inf, char **av);
void			ft_uspleep(unsigned long tm);
void			*routine(void *arg);
void			show_msg(t_philo *inf, char *s, int time);
size_t			ft_strlen(const char *s);
long			get_t(void);

#endif
