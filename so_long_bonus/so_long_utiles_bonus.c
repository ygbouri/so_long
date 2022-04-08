/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:30:42 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/06 05:21:26 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	keywb(t_mx *so)
{
	so->h = checkplayerb(so);
	if (so->str[--so->i][so->j] == 'Y')
	{
		ft_printf("Game over!!");
		exit(0);
	}
	if (so->str[so->i][so->j] != 'E')
	{
		if (so->str[so->i][so->j] != '1')
		{
			so->str[++so->i][so->j] = '0';
			so->str[--so->i][so->j] = 'P';
			so->commove++;
			ft_printf("move=> %d\n", so->commove);
		}
	}
	else if (checkcolleb(so) == 0)
	{
		ft_printf("Game finish! good work");
		exit(0);
	}
	++so->wcom;
}

void	keyab(t_mx *so)
{
	so->h = checkplayerb(so);
	if (so->str[so->i][--so->j] == 'Y')
	{
		ft_printf("Game over!!");
		exit(0);
	}
	if (so->str[so->i][so->j] != 'E')
	{
		if (so->str[so->i][so->j] != '1')
		{
			so->str[so->i][++so->j] = '0';
			so->str[so->i][--so->j] = 'P';
			so->commove++;
			ft_printf("move=> %d\n", so->commove);
		}
	}
	else if (checkcolleb(so) == 0)
	{
		ft_printf("Game finish! good work");
		exit(0);
	}
	++so->acom;
}

void	keysb(t_mx *so)
{
	so->h = checkplayerb(so);
	if (so->str[++so->i][so->j] == 'Y')
	{
		ft_printf("Game over!!");
		exit(0);
	}
	if (so->str[so->i][so->j] != 'E')
	{
		if (so->str[so->i][so->j] != '1')
		{
			so->str[--so->i][so->j] = '0';
			so->str[++so->i][so->j] = 'P';
			so->commove++;
			ft_printf("move=> %d\n", so->commove);
		}
	}
	else if (checkcolleb(so) == 0)
	{
		ft_printf("Game finish! good work");
		exit(0);
	}
	++so->scom;
}

void	keydb(t_mx *so)
{
	so->h = checkplayerb(so);
	if (so->str[so->i][++so->j] == 'Y')
	{
		ft_printf("Game over!!");
		exit(0);
	}
	if (so->str[so->i][so->j] != 'E' )
	{
		if (so->str[so->i][so->j] != '1')
		{
			so->str[so->i][--so->j] = '0';
			so->str[so->i][++so->j] = 'P';
			so->commove++;
			ft_printf("move=> %d\n", so->commove);
		}
	}
	else if (checkcolleb(so) == 0)
	{
		ft_printf("Game finish! good work");
		exit(0);
	}
	++so->dcom;
}

int	checkcolleb(t_mx *so)
{
	so->chi = 1;
	so->chj = 1;
	so->c = 0;
	while (so->chi < so->lenmap - 1)
	{
		so->chj = 1;
		while (so->chj < so->lenline - 1)
		{
			if (so->str[so->chi][so->chj] == 'C')
				so->c++;
			so->chj++;
		}
		so->chi++;
	}
	if (so->c == 0)
		return (0);
	return (1);
}
