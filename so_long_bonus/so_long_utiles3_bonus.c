/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:11:02 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/08 02:58:25 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_substrb(char *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		p = (char *)malloc((ft_strlen(s) - start) + 1);
	else
		p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		p[i] = s[start];
		start++;
		i++;
		len--;
	}
	p[i] = '\0';
	free(s);
	return (p);
}

int	checkplayerb(t_mx *so)
{
	so->i = 1;
	so->j = 1;
	while (so->i < so->lenmap - 1)
	{
		so->j = 1;
		while (so->j < so->lenline - 1)
		{
			if (so->str[so->i][so->j] == 'P')
				return (0);
			so->j++;
		}
		so->i++;
	}
	return (0);
}

int	heighoneb(t_mx *so)
{
	so->i = 1;
	so->j = 1;
	so->one = 0;
	while (so->j < (int)ft_strlen(so->str[so->i]) - 1)
	{
		so->i = 1;
		so->one = 0;
		while (so->i < so->lenmap - 1)
		{
			if (so->str[so->i][so->j] == '1')
				so->one++;
			so->i++;
		}
		if (so->one == so->lenmap - 2)
			return (1);
		so->j++;
	}
	return (0);
}

void	pushimgmapb(t_mx *so)
{
	initialiserb(so);
	mlx_clear_window(so->mlx, so->mlx_win);
	so->i = 0;
	so->j = 0;
	so->c = 0;
	so->e = 0;
	while (so->str[so->i])
	{
		so->j = 0;
		so->c = 0;
		while (so->str[so->i][so->j])
		{
			printimgb(so, so->img_zero);
			conditionsb(so);
			so->c += 64;
			so->j++;
		}
		so->e += 64;
		so->i++;
	}
}

void	initb(t_mx *so)
{
	stringimgb(so);
	so->img_tree = mlx_xpm_file_to_image(so->mlx, so->tree, &so->w, &so->h);
	so->img_zero = mlx_xpm_file_to_image(so->mlx, so->bground, &so->w, &so->h);
	so->img_c = mlx_xpm_file_to_image(so->mlx, so->collect, &so->w, &so->h);
	so->img_fone = mlx_xpm_file_to_image(so->mlx, so->frone, &so->w, &so->h);
	so->img_ftwo = mlx_xpm_file_to_image(so->mlx, so->frtwo, &so->w, &so->h);
	so->img_fthree = mlx_xpm_file_to_image(so->mlx, so->frthr, &so->w, &so->h);
	so->img_bone = mlx_xpm_file_to_image(so->mlx, so->baone, &so->w, &so->h);
	so->img_btwo = mlx_xpm_file_to_image(so->mlx, so->batwo, &so->w, &so->h);
	so->img_bthree = mlx_xpm_file_to_image(so->mlx, so->bathr, &so->w, &so->h);
	so->img_rone = mlx_xpm_file_to_image(so->mlx, so->rione, &so->w, &so->h);
	so->img_rtwo = mlx_xpm_file_to_image(so->mlx, so->ritwo, &so->w, &so->h);
	so->img_rthree = mlx_xpm_file_to_image(so->mlx, so->rithr, &so->w, &so->h);
	so->img_lone = mlx_xpm_file_to_image(so->mlx, so->leone, &so->w, &so->h);
	so->img_ltwo = mlx_xpm_file_to_image(so->mlx, so->letwo, &so->w, &so->h);
	so->img_lthree = mlx_xpm_file_to_image(so->mlx, so->lethr, &so->w, &so->h);
	so->img_e = mlx_xpm_file_to_image(so->mlx, so->doorclose, &so->w, &so->h);
	so->img_chair = mlx_xpm_file_to_image(so->mlx, so->chair, &so->w, &so->h);
	so->img_tree1 = mlx_xpm_file_to_image(so->mlx, so->tree1, &so->w, &so->h);
	so->img_nafora = mlx_xpm_file_to_image(so->mlx, so->nafora, &so->w, &so->h);
	so->img_wbrik = mlx_xpm_file_to_image(so->mlx, so->wabrik, &so->w, &so->h);
	so->img_cleft = mlx_xpm_file_to_image(so->mlx, so->chleft, &so->w, &so->h);
	so->img_eneo = mlx_xpm_file_to_image(so->mlx, so->eneone, &so->w, &so->h);
	so->img_enet = mlx_xpm_file_to_image(so->mlx, so->enetwo, &so->w, &so->h);
}
