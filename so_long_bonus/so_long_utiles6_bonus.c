/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles6_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:34:54 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/08 03:26:13 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	stringimgb(t_mx *so)
{
	so->tree = "img/AnyConv.com__tree.xpm";
	so->chair = "img/AnyConv.com__chair.xpm";
	so->dopen = "img/AnyConv.com__dooropened.xpm";
	so->doorclose = "img/AnyConv.com__doorclosed.xpm";
	so->bground = "img/AnyConv.com__background1.xpm";
	so->collect = "img/AnyConv.com__collect.xpm";
	so->baone = "img/AnyConv.com__lofiback.xpm";
	so->batwo = "img/AnyConv.com__lofiback1.xpm";
	so->bathr = "img/AnyConv.com__lofiback2.xpm";
	so->frone = "img/AnyConv.com__lofifront.xpm";
	so->frtwo = "img/AnyConv.com__lofifront1.xpm";
	so->frthr = "img/AnyConv.com__lofifront2.xpm";
	so->rione = "img/AnyConv.com__lofiright.xpm";
	so->ritwo = "img/AnyConv.com__lofiright1.xpm";
	so->rithr = "img/AnyConv.com__lofiright2.xpm";
	so->leone = "img/AnyConv.com__lofileft.xpm";
	so->letwo = "img/AnyConv.com__lofileft1.xpm";
	so->lethr = "img/AnyConv.com__lofileft2.xpm";
	so->tree1 = "img/AnyConv.com__tree1.xpm";
	so->nafora = "img/AnyConv.com__nafora.xpm";
	so->wabrik = "img/AnyConv.com__wallbrik.xpm";
	so->chleft = "img/AnyConv.com__chairleft.xpm";
	so->eneone = "img/ee2.xpm";
	so->enetwo = "img/ee3.xpm";
}

int	checkennemi(t_mx *so)
{
	so->ie = 1;
	so->je = 1;
	while (so->ie < so->lenmap - 1)
	{
		so->je = 1;
		while (so->je < so->lenline - 1)
		{
			if (so->str[so->ie][so->je] == 'Y')
				return (0);
			so->je++;
		}
		so->ie++;
	}
	return (0);
}

void	moveennemi(t_mx *so)
{
	so->h = checkennemi(so);
	if (so->str[so->ie][++so->je] != 'P')
	{
		if (so->str[so->ie][so->je] != '1')
		{
			so->str[so->ie][--so->je] = '0';
			so->str[so->ie][++so->je] = 'Y';
		}
		else
		{
			so->str[so->ie][--so->je] = '0';
			so->str[so->ie][--so->je] = 'Y';
		}
	}
}

void	conditionsb(t_mx *so)
{
	if (so->str[so->i][so->j] == '1')
		pushwallb(so);
	if (so->str[so->i][so->j] == 'C')
		printimgb(so, so->img_c);
	if (so->str[so->i][so->j] == 'P')
		moveplayerb(so);
	if (so->str[so->i][so->j] == 'E')
		printimgb(so, so->img_e);
	if (so->str[so->i][so->j] == 'Y')
	{
		animation(so);
	}
}

void	initialisertwob(t_mx *so)
{
	so->i = 0;
	so->j = 0;
	so->h = 0;
	so->w = 0;
	so->e = 0;
	so->c = 0;
	so->wcom = 0;
	so->commove = 0;
	so->dcom = 0;
	so->scom = 0;
	so->acom = 0;
	so->keys = -1;
}
