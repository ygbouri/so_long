/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:11:11 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/04 01:45:02 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int key, t_mx *so)
{
	if (key == 13)
		keyw(so);
	else if (key == 0)
		keya(so);
	else if (key == 1)
		keys(so);
	else if (key == 2)
		keyd(so);
	else if (key == 53)
	{
		ft_printf("Game finish! goodbye");
		exit(0);
	}
	if (checkcolle(so) == 0)
		so->img_e = mlx_xpm_file_to_image(so->mlx, so->dopen, &so->w, &so->h);
	if ((key == 0) || (key == 2) || (key == 1) || (key == 13))
	{
		so->keys = key;
		pushimgmap(so);
	}
	return (0);
}

void	wallintermap(t_mx *so)
{
	if (so->comtr == 0)
	{
		printimg(so, so->img_tree1);
		so->comtr = 1;
	}
	else if (so->comchleft == 0)
	{
		printimg(so, so->img_cleft);
		so->comchleft = 1;
	}
	else if (so->comch == 0)
	{
		printimg(so, so->img_chair);
		so->comch = 1;
	}
	else if (so->comnafora == 0)
	{
		printimg(so, so->img_nafora);
		so->comnafora = 1;
	}
	else
	{
		printimg(so, so->img_tree);
		initialiser(so);
	}
}

void	moveplayertoo(t_mx *so)
{
	if (so->keys == 0)
	{
		if (so->acom == 0)
			printimg(so, so->img_lone);
		else if (so->acom == 1)
			printimg(so, so->img_ltwo);
		else if (so->acom == 2)
		{
			printimg(so, so->img_lthree);
			so->acom = -1;
		}
	}
	else if (so->keys == 2)
	{
		if (so->dcom == 0)
			printimg(so, so->img_rone);
		else if (so->dcom == 1)
			printimg(so, so->img_rtwo);
		else if (so->dcom == 2)
		{
			printimg(so, so->img_rthree);
			so->dcom = -1;
		}
	}
}

void	movetfront(t_mx *so)
{
	printimg(so, so->img_fthree);
	so->scom = -1;
}

void	moveplayer(t_mx *so)
{
	if (so->keys == -1)
		printimg(so, so->img_fone);
	else if (so->keys == 13)
	{
		if (so->wcom == 0)
			printimg(so, so->img_bone);
		else if (so->wcom == 1)
			printimg(so, so->img_btwo);
		else if (so->wcom == 2)
		{
			printimg(so, so->img_bthree);
			so->wcom = -1;
		}
	}
	else if (so->keys == 1)
	{
		if (so->scom == 0)
			printimg(so, so->img_fone);
		else if (so->scom == 1)
			printimg(so, so->img_ftwo);
		else if (so->scom == 2)
			movetfront(so);
	}
	moveplayertoo(so);
}
