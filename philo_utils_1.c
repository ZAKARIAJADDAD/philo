/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:41:38 by zjaddad           #+#    #+#             */
/*   Updated: 2023/04/10 22:38:47 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	show_msg(t_philo *inf, char *s, int time)
{
	(void)time;
	pthread_mutex_lock(inf->msg_mutex);
	if (inf->situ == 1)
	{
		printf("%6ld ms: {%d} %s\n", get_t() - inf->start_t, \
			inf->id, s);
	}
	pthread_mutex_unlock(inf->msg_mutex);
}

int	checkeat(int *tb, int size)
{
	int	i;

	i = 0;
	while (tb[i] == 1)
		i++;
	if (i == size)
		return (1);
	return (0);
}

void	supervisor(t_philo *inf, int i)
{
	int	tb[200];

	ft_memset(tb, 0, 200 * 4);
	while (1)
	{
		pthread_mutex_lock(&inf[i].n_eat_mutex);
		if (!inf[i].n_eat)
			tb[i] = 1;
		pthread_mutex_unlock(&inf[i].n_eat_mutex);
		if (checkeat(tb, inf->n_p))
			return ;
		pthread_mutex_lock(&inf[i].lock_mutex);
		if (get_t() - inf[i].tmp_t >= inf->t_die)
		{
			pthread_mutex_lock(inf->msg_mutex);
			printf("%6ld ms: \e[0;31m{%d} died\n", \
				(get_t() - inf[i].start_t), inf[i].id);
			return ;
		}
		pthread_mutex_unlock(&inf[i].lock_mutex);
		i++;
		if (i == inf->n_p)
			i = 0;
	}
}

int	init_simulation(t_philo	*inf, long start)
{
	int	i;

	i = -1;
	pthread_mutex_init(inf[0].msg_mutex, NULL);
	while (++i < inf->n_p)
	{
		pthread_mutex_init(&inf[i].n_eat_mutex, NULL);
		pthread_mutex_init(&inf[i].lock_mutex, NULL);
		pthread_mutex_init(&inf->fork[i], NULL);
	}
	i = -1;
	start = get_t();
	while (++i < inf->n_p)
	{
		inf[i].id = i + 1;
		inf[i].situ = 1;
		inf[i].start_t = start;
		inf[i].tmp_t = start;
		if (pthread_create(&inf[i].philo, NULL, &pre_routine, &inf[i]))
			return (0);
	}
	supervisor(inf, 0);
	return (1);
}
