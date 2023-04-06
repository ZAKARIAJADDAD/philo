/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:40:19 by zjaddad           #+#    #+#             */
/*   Updated: 2023/04/06 23:16:09 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo **inf, char **av)
{
	int	i = -1;
	int	np = ft_atoi(av[1]);
	*inf = malloc(sizeof(t_philo) * np);
	// (*inf)->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if(!*inf)
		return ;
	while (++i < np)
	{
		(*inf)[i].n_p = np;
		(*inf)[i].t_die = ft_atoi(av[2]);
		(*inf)[i].t_eat = ft_atoi(av[3]);
		(*inf)[i].t_slp = ft_atoi(av[4]);
		if (av[5])
			(*inf)[i].n_eat = ft_atoi(av[5]);
		else
			(*inf)[i].n_eat = -1;
	}
}

long get_t(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 10000));
}

void	*routine(void *arg)
{
	t_philo	*inf;

	inf = (t_philo *)arg;
	while (inf->n_eat && inf->situ == 1)
	{
		pthread_mutex_lock(&inf->fork);
		show_msg(inf, "has taken the fisrt fork", 0);
		if (inf->n_p == 1)
			return (NULL);
		pthread_mutex_lock(&(inf + inf->next)->fork);
		show_msg(inf, "has taken the second fork", 0);
		inf->tmp_t = get_t();
		show_msg(inf, "is eating", inf->t_eat);
		usleep(inf->t_eat);
		pthread_mutex_unlock(&(inf + inf->next)->fork);
		pthread_mutex_unlock(&inf->fork);
		show_msg(inf, "is sleeping", inf->t_slp);
		usleep(inf->t_slp);
		show_msg(inf, "is thinking", 0);
		if(inf->n_eat != -1)
			inf->n_eat--;
	}
	return (NULL);
	//usleep(50);
}

int	main(int ac, char **av)
{
	t_philo	*inf = NULL;

	if (ac == 5 || ac == 6)
	{
		int i = -1;
		if (param_check(av, ac) < 0)
			return (print_error(param_check(av, ac)));
		init_struct(&inf, av);
		if (!init_simulation(inf))
			return (0);
		while(++i < inf->n_p)
			if (pthread_join(inf[i].philo, NULL))
				return(0);
		i = -1;
		while(++i < inf->n_p)
			if (pthread_mutex_destroy(&inf[i].fork))
				return(0);
		free(inf);
	}
	else
		return(write(2, "Error: Invalid Number of Arguments.\n", 36));
}

//allocate to pthread_t & forks;
//create init_strcut function to fill all data that you need
//fill in this function your struct (t_crt / t_eat / t_slp / t_die...)
//make sleep (200 microsec) in routine function;
//make mutex_lock/mutex_unlock 2 times because each philo-
//must take 2 forks
//make infinite loop in routine function
