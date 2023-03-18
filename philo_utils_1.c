/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:41:38 by zjaddad           #+#    #+#             */
/*   Updated: 2023/03/18 15:41:33 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	init_simulation(t_philo	**inf)
{
	long	start;
	int		i;

	i = 0;
	while (i < (*inf)->n_p)
	{
		if (pthread_mutex_init(&(*inf + i)->fork, NULL))
			return (0);
		i++;
	}
	i = 0;
	start = get_t();
	while (i < (*inf)->n_p)
	{
		(*inf)->id = i + 1;
		i++;
	}
}