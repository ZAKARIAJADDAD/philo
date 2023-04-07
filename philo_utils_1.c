/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:41:38 by zjaddad           #+#    #+#             */
/*   Updated: 2023/04/07 03:18:47 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	show_msg(t_philo *inf, char *s, int time)
{
	if (inf->situ == 1)
	{
		inf->crt_t = get_t();
		printf("%6ld ms: {%d} %s\n", inf->crt_t - inf->start_t, \
			inf->id, s);
		if (time)
		{
			inf->crt_t = get_t();
			while (inf->situ == 1 && get_t() - inf->crt_t < time)
				usleep(100);
		}
	}
}

void	supervisor(t_philo *inf)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (inf[i].n_eat)
	{
		inf[i].last_eat = get_t() - inf[i].tmp_t;
		if (inf[i].last_eat >= inf[i].t_die)
		{
			while (++j < inf->n_p)
				inf[j].situ = 0;
			inf[i].crt_t = get_t();
			printf("%6ld ms: \e[0;31m{%d} died\n", \
				(inf[i].crt_t - inf[i].start_t), inf[i].id);
			return ;
		}
		i++;
		if (i == inf->n_p)
			i = 0;
	}
}

int	init_simulation(t_philo	*inf, long start)
{
	int		i;

	i = -1;
	while (++i < inf->n_p)
	{
		if (pthread_mutex_init(&inf[i].fork, NULL))
			return (0);
	}
	i = -1;
	start = get_t();
	while (++i < inf->n_p)
	{
		inf[i].id = i + 1;
		inf[i].next = 1;
		if (inf[i].id == inf[i].n_p)
			inf[i].next = -(inf[i].n_p) + 1;
		inf[i].situ = 1;
		inf[i].start_t = start;
		inf[i].tmp_t = start;
		if (pthread_create(&inf[i].philo, NULL, &routine, &inf[i]))
			return (0);
		usleep(50);
	}
	supervisor(inf);
	return (1);
}
