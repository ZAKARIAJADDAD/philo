/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:40:19 by zjaddad           #+#    #+#             */
/*   Updated: 2023/03/15 23:09:45 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo **inf)
{
	*inf = malloc(sizeof(struct philo));
	if(!inf)
		return ;
}

void	routine(void *arg)
{
	
}

int	main(int ac, char **av)
{
	t_philo	*inf = NULL;

	if (ac == 5 || ac == 6)
	{
		init_struct(&inf);
		if (param_check(av, &inf) == -1)
			return (write(2, "Invalid Argument.\n", 18));
		while (inf->i < inf->n_p)
		{
			pthread_create(&inf->philo[inf->i], NULL, routine, &inf);
			inf->i++;
		}
	}
}


//allocate to pthread_t & forks;
//create init_strcut function to fill all data that you need
//fill in this function your struct (t_crt / t_eat / t_slp / t_die...)
//make sleep (200 microsec) in routine function;
//make mutex_lock/mutex_unlock 2 times because each philo-
//must take 2 forks
//make infinite loop in routine function