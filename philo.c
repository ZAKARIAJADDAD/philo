/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:40:19 by zjaddad           #+#    #+#             */
/*   Updated: 2023/04/10 21:38:25 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo **inf, char **av)
{
	int	i;
	int	np;

	i = -1;
	np = ft_atoi(av[1]);
	*inf = malloc(sizeof(t_philo) * np);
	(*inf)->fork = malloc(sizeof(pthread_mutex_t) * np);
	(*inf)->msg_mutex = malloc(sizeof(pthread_mutex_t) * 1);
	if (!(*inf) || !inf || !(*inf)->fork || !(*inf)->msg_mutex)
		return ;
	while (++i < np)
	{
		(*inf)[i].n_p = np;
		(*inf)[i].fork = (*inf)->fork;
		(*inf)[i].msg_mutex = (*inf)->msg_mutex;
		(*inf)[i].t_die = ft_atoi(av[2]);
		(*inf)[i].t_eat = ft_atoi(av[3]);
		(*inf)[i].t_slp = ft_atoi(av[4]);
		if (av[5])
			(*inf)[i].n_eat = ft_atoi(av[5]);
		else
			(*inf)[i].n_eat = -1;
	}
}

unsigned long	get_t(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*routine(t_philo *inf)
{
	while (1)
	{
		pthread_mutex_lock(&inf->fork[inf->id - 1]);
		show_msg(inf, "has taken a fork", 0);
		pthread_mutex_lock(&inf->fork[inf->id % inf->n_p]);
		show_msg(inf, "has taken a fork", 0);
		pthread_mutex_lock(&inf->lock_mutex);
		inf->tmp_t = get_t();
		pthread_mutex_unlock(&inf->lock_mutex);
		show_msg(inf, "is eating", inf->t_eat);
		ft_usleep(inf->t_eat);
		pthread_mutex_unlock(&inf->fork[inf->id % inf->n_p]);
		pthread_mutex_unlock(&inf->fork[inf->id - 1]);
		show_msg(inf, "is sleeping", inf->t_slp);
		ft_usleep(inf->t_slp);
		show_msg(inf, "is thinking", 0);
		pthread_mutex_lock(&inf->n_eat_mutex);
		if (inf-> n_eat > 0)
			inf->n_eat--;
		pthread_mutex_unlock(&inf->n_eat_mutex);
	}
	return (NULL);
}

void	*pre_routine(void *arg)
{
	t_philo	*inf;

	inf = (t_philo *)arg;
	if (!(inf->id % 2))
		usleep(1000);
	routine(inf);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo	*inf;
	int		i;
	long	start;

	inf = NULL;
	start = 0;
	if (ac == 5 || ac == 6)
	{
		if (param_check(av) < 0)
			return (print_error(param_check(av)));
		init_struct(&inf, av);
		if (!init_simulation(inf, start))
			return (0);
		i = -1;
		while (++i < inf->n_p)
			if (pthread_mutex_destroy(&inf->fork[i]))
				return (0);
	}
	else
		return (write(2, "Error: Invalid Number of Arguments.\n", 36));
}
