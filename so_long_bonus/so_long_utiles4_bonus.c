/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles4_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:11:11 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/06 08:21:17 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keyhookb(int key, t_mx *so)
{
	if (key == 13)
		keywb(so);
	else if (key == 0)
		keyab(so);
	else if (key == 1)
		keysb(so);
	else if (key == 2)
		keydb(so);
	else if (key == 53)
	{
		ft_printf("Game finish! goodbye");
		exit(0);
	}
	if (checkcolleb(so) == 0)
		so->img_e = mlx_xpm_file_to_image(so->mlx, so->dopen, &so->w, &so->h);
	if ((key == 0) || (key == 2) || (key == 1) || (key == 13))
	{
		so->keys = key;
		moveennemi(so);
		pushimgmapb(so);
		so->s = ft_itoa(so->commove);
		mlx_string_put(so->mlx, so->mlx_win, 0, 0, 0x00FF0000, so->s);
		free(so->s);
	}
	return (0);
}

void	wallintermapb(t_mx *so)
{
	if (so->comtr == 0)
	{
		printimgb(so, so->img_tree1);
		so->comtr = 1;
	}
	else if (so->comchleft == 0)
	{
		printimgb(so, so->img_cleft);
		so->comchleft = 1;
	}
	else if (so->comch == 0)
	{
		printimgb(so, so->img_chair);
		so->comch = 1;
	}
	else if (so->comnafora == 0)
	{
		printimgb(so, so->img_nafora);
		so->comnafora = 1;
	}
	else
	{
		printimgb(so, so->img_tree);
		initialiserb(so);
	}
}

void	moveplayertoob(t_mx *so)
{
	if (so->keys == 0)
	{
		if (so->acom == 0)
			printimgb(so, so->img_lone);
		else if (so->acom == 1)
			printimgb(so, so->img_ltwo);
		else if (so->acom == 2)
		{
			printimgb(so, so->img_lthree);
			so->acom = -1;
		}
	}
	else if (so->keys == 2)
	{
		if (so->dcom == 0)
			printimgb(so, so->img_rone);
		else if (so->dcom == 1)
			printimgb(so, so->img_rtwo);
		else if (so->dcom == 2)
		{
			printimgb(so, so->img_rthree);
			so->dcom = -1;
		}
	}
}

void	movetfrontb(t_mx *so)
{
	printimgb(so, so->img_fthree);
	so->scom = -1;
}

void	moveplayerb(t_mx *so)
{
	if (so->keys == -1)
		printimgb(so, so->img_fone);
	else if (so->keys == 13)
	{
		if (so->wcom == 0)
			printimgb(so, so->img_bone);
		else if (so->wcom == 1)
			printimgb(so, so->img_btwo);
		else if (so->wcom == 2)
		{
			printimgb(so, so->img_bthree);
			so->wcom = -1;
		}
	}
	else if (so->keys == 1)
	{
		if (so->scom == 0)
			printimgb(so, so->img_fone);
		else if (so->scom == 1)
			printimgb(so, so->img_ftwo);
		else if (so->scom == 2)
			movetfrontb(so);
	}
	moveplayertoob(so);
}
