/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:08:13 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/08 03:42:07 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation(t_mx *so)
{
	if (so->ai == 0)
	{
		so->aj = 0;
		while (so->aj < 8)
		{
			printimgb(so, so->img_eneo);
			so->aj++;
		}
		so->ai++;
	}
	else if (so->ai == 1)
	{
		so->aj = 0;
		while (so->aj < 8)
		{
			printimgb(so, so->img_enet);
			so->aj++;
		}
		so->ai = 0;
	}
}

void	maintoob(t_mx *so)
{
	int	t;
	int	l;

	t = so->lenmap * 64;
	l = so->lenline * 64;
	so->mlx = mlx_init();
	if (!so->mlx)
	{
		ft_printf("erreur de connexion");
		return ;
	}
	so->mlx_win = mlx_new_window(so->mlx, l, t, "so_long");
	initb(so);
	pushimgmapb(so);
	mlx_hook(so->mlx_win, 2, 0, keyhookb, so);
	mlx_hook(so->mlx_win, 17, 0, closewinb, so);
	mlx_loop(so->mlx);
}

int	main(int ar, char **arg)
{
	t_mx	solong;

	if (ar == 2)
	{
		if (checkexeb(ft_strrchrb(arg[1], '.')) == 0)
		{
			solong.ai = 0;
			solong.lenmap = countmapb(arg[1]);
			if (checkmapb(&solong, arg[1]) == 1)
				ft_printf("map incorrect");
			else
			{
				initialisertwob(&solong);
				initialiserb(&solong);
				maintoob(&solong);
			}
		}
		else
			ft_printf("exetension incorrect");
		return (0);
	}
}
//protection map vide 