/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:08:13 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/08 03:40:40 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maintoo(t_mx *so)
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
	init(so);
	pushimgmap(so);
	mlx_hook(so->mlx_win, 2, 0, keyhook, so);
	mlx_hook(so->mlx_win, 17, 0, closewin, so);
	mlx_loop(so->mlx);
}

int	main(int ar, char **arg)
{
	t_mx	solong;

	if (ar == 2)
	{
		if (checkexe(ft_strrchr(arg[1], '.')) == 0)
		{
			solong.lenmap = countmap(arg[1]);
			if (checkmap(&solong, arg[1]) == 1)
				ft_printf("map incorrect");
			else
			{
				initialisertwo(&solong);
				initialiser(&solong);
				maintoo(&solong);
			}
		}
		else
			ft_printf("exetension incorrect");
		return (0);
	}
}
