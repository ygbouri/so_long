/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:34:47 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/04 01:46:05 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printimg(t_mx *so, void *pa)
{
	mlx_put_image_to_window(so->mlx, so->mlx_win, pa, so->c, so->e);
}

void	pushwall(t_mx *so)
{
	if ((so->i == 0 && so->j < so->lenline)
		|| (so->j < so->lenline && so->i == so->lenmap - 1))
		printimg(so, so->img_wbrik);
	if ((so->j == 0 && so->i < so->lenmap - 1)
		|| (so->j == so->lenline - 1 && so->i < so->lenmap - 1))
		printimg(so, so->img_tree1);
	else if (((so->i > 0) && (so->i < so->lenmap - 1))
		&& ((so->j > 0) && (so->j < so->lenline)))
		wallintermap(so);
}

int	closewin(int key, t_mx *so)
{
	(void)key;
	(void)so;
	ft_printf("game closed!!!!");
	exit(0);
}

void	initialiser(t_mx *so)
{
	so->comchleft = 0;
	so->comch = 0;
	so->comnafora = 0;
	so->comtr = 0;
}

int	checkline(t_mx *so)
{
	if (checkfirstlastline(so) == 0)
	{
		if (so->lenmap != so->lenline)
		{			
			if (checkcountone(so) == 1)
				return (1);
			if (countelement(so) == 1)
				return (1);
			if (checkcaracter(so) == 1)
				return (1);
			if (heighone(so) == 1)
				return (1);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
