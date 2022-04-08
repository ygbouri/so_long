/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles5_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:34:47 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/06 08:18:24 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	printimgb(t_mx *so, void *pa)
{
	mlx_put_image_to_window(so->mlx, so->mlx_win, pa, so->c, so->e);
}

void	pushwallb(t_mx *so)
{
	if ((so->i == 0 && so->j < so->lenline)
		|| (so->j < so->lenline && so->i == so->lenmap - 1))
		printimgb(so, so->img_wbrik);
	if ((so->j == 0 && so->i < so->lenmap - 1)
		|| (so->j == so->lenline - 1 && so->i < so->lenmap - 1))
		printimgb(so, so->img_tree1);
	else if (((so->i > 0) && (so->i < so->lenmap - 1))
		&& ((so->j > 0) && (so->j < so->lenline)))
		wallintermapb(so);
}

int	closewinb(int key, t_mx *so)
{
	(void)key;
	(void)so;
	ft_printf("game closed!!!!");
	exit(0);
}

void	initialiserb(t_mx *so)
{
	so->comchleft = 0;
	so->comch = 0;
	so->comnafora = 0;
	so->comtr = 0;
}

int	checklineb(t_mx *so)
{
	so->y = 0;
	if (checkfirstlastlineb(so) == 0)
	{
		if (so->lenmap != so->lenline)
		{			
			if (checkcountoneb(so) == 1)
				return (1);
			if (countelementb(so) == 1)
				return (1);
			if (checkcaracterb(so) == 1)
				return (1);
			if (heighoneb(so) == 1)
				return (1);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
