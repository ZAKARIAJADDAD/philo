/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:40:19 by zjaddad           #+#    #+#             */
/*   Updated: 2023/03/15 20:36:05 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *arg)
{
	
}

int	main(int ac, char **av)
{
	t_philo	*inf;
	t_p_inf	*fill = NULL;

	fill = malloc(sizeof(struct p_inf));
	if(!fill)
		return (0);
	if (ac == 5 || ac == 6)
	{
		if (param_check(av, &fill) == -1)
			return (write(2, "Invalid Argument.\n", 18));
		while (fill->i < fill->n_p)
		{
			pthread_create(&inf->fork[fill->n_p], NULL, routine, &inf);
			fill->i++;
		}
	}
}
