/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:34:01 by zjaddad           #+#    #+#             */
/*   Updated: 2023/04/10 00:34:33 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *vp, int c, size_t lent)
{
	size_t	i;

	i = 0;
	while (i < lent)
	{
		((unsigned char *)vp)[i] = (unsigned char)c;
		i++;
	}
	return (vp);
}
