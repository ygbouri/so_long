/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:58:00 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/06 05:20:28 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_reserver(char *p, int n, int i)
{
	if (n <= 0)
		p = (char *)malloc(i + 2);
	else
		p = (char *)malloc(i + 1);
	return (p);
}

static int	ft_compter(long x)
{
	int	i;

	i = 0;
	if (x < 0)
		x *= (-1);
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*p;
	int			i;
	long		nbr;

	p = NULL;
	nbr = n;
	i = ft_compter(nbr);
	p = ft_reserver(p, n, i);
	if (!p)
		return (NULL);
	if (nbr < 0)
	{
		p[0] = '-';
		nbr *= (-1);
		i++;
	}
	if (n == 0)
		p[i++] = 0 + 48;
	p[i] = '\0';
	while (nbr > 0)
	{
		p[--i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (p);
}
