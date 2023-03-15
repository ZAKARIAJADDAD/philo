/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:22:36 by zjaddad           #+#    #+#             */
/*   Updated: 2023/03/15 23:07:45 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	t_ati	var;

	var.i = 0;
	var.result = 0;
	while ((s[var.i] == ' ' || (s[var.i] >= 9 && s[var.i] <= 13)))
		var.i++;
	if ((s[var.i] == '+' || s[var.i] == '-') && s[var.i + 1] != '\0')
	{
		if (s[var.i] == '-')
			return (-1);
		var.i++;
	}
	while (s[var.i])
	{
		if (s[var.i] < '0' || s[var.i] > '9')
			return (-1);
		var.result = var.result * 10 + (s[var.i] - 48);
		var.i++;
	}
	if (var.result > INT_MAX)
		return (-1);
	return (var.result);
}

int	white_space(char *p)
{
	int	i = 0;

	while (p[i])
	{
		if (p[i] == ' ' || (p[i] >= 9 && p[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	param_check(char **av, t_philo **inf)
{
	int	i;
	int	j;
	// t_p_inf	*fill;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0' || white_space(av[i]) == 0)
			return (-1);
		j = ft_atoi(av[i]);
		if (j == -1)
			break;
		i++;
	}
	(*inf)->n_p = ft_atoi(av[1]);
	return (j);
}
