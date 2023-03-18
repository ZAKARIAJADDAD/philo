/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:40:19 by zjaddad           #+#    #+#             */
/*   Updated: 2023/03/18 15:36:08 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo **inf, char **av)
{
	*inf = malloc(sizeof(struct philo) * ft_atoi(av[1]));
	(*inf)->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if(!inf)
		return ;
	(*inf)->n_p = ft_atoi(av[1]);
	(*inf)->t_die = ft_atoi(av[2]);
	(*inf)->t_eat = ft_atoi(av[3]);
	(*inf)->t_slp = ft_atoi(av[4]);
	if (av[5])
		(*inf)->n_eat = ft_atoi(av[5]);
	else
		(*inf)->n_eat = -1;	
}

unsigned long get_t(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 10000));
}

void	ft_uspleep(unsigned long tm)
{
	unsigned long sv = get_t();

	while (get_t() - sv <= tm)
	{
		usleep(100);
	}
}

void	routine(void *arg)
{
	t_philo	*inf;

	inf = (t_philo *)arg;
	while (1)
	{
		//eat
		//print_spleep
		//sleep_timetosleep
		//print_thinking
		
	}
	uspleep(50);
}

int	main(int ac, char **av)
{
	t_philo	*inf = NULL;

	if (ac == 5 || ac == 6)
	{
		if (param_check(av) == -1)
			return (write(2, "Invalid Argument.\n", 18));
		init_struct(&inf, av);
		if (!init_simulation(&inf))
			return (0);
		// while (inf->i < inf->n_p)
		// {
		// 	inf[inf->i].fork = inf[0].fork;
		// 	inf->idx = inf->i + 1;
		// 	pthread_create(&inf->philo[inf->i], NULL, *routine, &inf);
		// 	inf->i++;
		// }
	}
}


//allocate to pthread_t & forks;
//create init_strcut function to fill all data that you need
//fill in this function your struct (t_crt / t_eat / t_slp / t_die...)
//make sleep (200 microsec) in routine function;
//make mutex_lock/mutex_unlock 2 times because each philo-
//must take 2 forks
//make infinite loop in routine function 