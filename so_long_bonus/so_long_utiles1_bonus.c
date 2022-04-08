/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 05:38:50 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/06 08:18:30 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	countelementb(t_mx *so)
{
	so->c = 0;
	so->e = 0;
	so->p = 0;
	so->i = 0;
	so->j = 1;
	while (so->j < so->lenmap - 1)
	{
		so->i = 0;
		while (so->str[so->j][so->i])
		{
			if (so->str[so->j][so->i] == 'C')
				so->c++;
			if (so->str[so->j][so->i] == 'E')
				so->e++;
			if (so->str[so->j][so->i] == 'P')
				so->p++;
			if (so->str[so->j][so->i] == 'Y')
				so->y++;
			so->i++;
		}
		so->j++;
	}
	if (so->c > 0 && so->p == 1 && so->e == 1 && so->y == 1)
		return (0);
	return (1);
}

int	checkfirstlastlineb(t_mx *so)
{
	so->j = 0;
	while (so->str[0][so->j])
	{
		if (so->str[0][so->j] == '1')
			so->j++;
		else
			return (1);
	}
	so->j = 0;
	while (so->str[so->lenmap - 1][so->j] != '\0')
	{
		if (so->str[so->lenmap - 1][so->j] == '1')
			so->j++;
		else
			return (1);
	}
	return (0);
}

void	cutnewlinetoob(t_mx *so)
{
	int	i;

	i = 1;
	so->lenline = (int)ft_strlen(so->str[0]);
	while (so->str[i] && i < so->lenmap - 1)
	{
		if ((int)ft_strlen(so->str[i]) != so->lenline)
		{
			ft_printf("map incorrect");
			exit(0);
		}
		i++;
	}
	if (!so->str || !so->str)
		exit (-1);
	if ((int)ft_strlen(so->str[i]) != so->lenline - 1)
	{
		ft_printf("map incorrect");
		exit(0);
	}
}

void	cutnewlineb(t_mx *so)
{
	int	i;

	i = 0;
	cutnewlinetoob(so);
	while (i < so->lenmap)
	{
		so->str[i] = ft_substrb(so->str[i], 0, so->lenline - 1);
		i++;
	}
	i = 1;
	so->lenline = (int)ft_strlen(so->str[0]);
}

int	checkmapb(t_mx *so, char *str)
{
	int	fd;

	so->j = 0;
	fd = 0;
	if (so->lenmap == 0)
		return (1);
	so->str = (char **)malloc((so->lenmap + 1) * sizeof(char *));
	if (!so->str)
		return (1);
	fd = open(str, O_RDONLY);
	while (so->j < so->lenmap)
	{
		so->str[so->j] = get_next_line(fd);
		so->j++;
	}
	so->str[so->j] = NULL;
	cutnewlineb(so);
	so->j = 0;
	return (checklineb(so));
}
