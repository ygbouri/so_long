/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:08:21 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/08 03:00:57 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include<fcntl.h>

char	*ft_strrchrb(char *str, int arg);
char	*ft_substrb(char *s, unsigned int start, size_t len);
int		checkexeb(char *str);
int		countmapb(char *str);
typedef struct s_mx
{
	int		lenmap;
	int		lenline;
	int		c;
	int		p;
	int		e;
	int		i;
	int		j;
	int		w;
	int		chj;
	int		chi;
	int		h;
	int		keys;
	int		wcom;
	int		acom;
	int		scom;
	int		dcom;
	int		one;
	int		comch;
	int		comchleft;
	int		comnafora;
	int		comtr;
	int		commove;
	int		ie;
	int		je;
	int		y;
	int		ai;
	int		aj;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img_zero;
	void	*img_e;
	void	*img_c;
	void	*img_bone;
	void	*img_btwo;
	void	*img_bthree;
	void	*img_fone;
	void	*img_ftwo;
	void	*img_fthree;
	void	*img_rone;
	void	*img_rtwo;
	void	*img_rthree;
	void	*img_lone;
	void	*img_ltwo;
	void	*img_lthree;
	void	*img_chair;
	void	*img_tree;
	void	*img_tree1;
	void	*img_nafora;
	void	*img_wbrik;
	void	*img_cleft;
	void	*img_eneo;
	void	*img_enet;
	char	*path;
	char	*tree;
	char	*doorclose;
	char	*dopen;
	char	*chair;
	char	*collect;
	char	*baone;
	char	*batwo;
	char	*bathr;
	char	*frone;
	char	*frtwo;
	char	*frthr;
	char	*rione;
	char	*ritwo;
	char	*rithr;
	char	*leone;
	char	*letwo;
	char	*lethr;
	char	*bground;
	char	*tree1;
	char	*nafora;
	char	*wabrik;
	char	*chleft;
	char	**str;
	char	*ene;
	char	*s;
	char	*eneone;
	char	*enetwo;
	char	*enetr;
}	t_mx;
int		checkfirstlastlineb(t_mx *so);
int		checkcountoneb(t_mx *so);
int		countelementb(t_mx *so);
int		checkcaracterb(t_mx *so);
int		checklineb(t_mx *so);
int		checkmapb(t_mx *so, char *str);
int		heighoneb(t_mx *so);
int		checkplayerb(t_mx *so);
int		checkcolleb(t_mx *so);
int		closewinb(int key, t_mx *so);
int		keyhookb(int key, t_mx *so);
void	keywb(t_mx *so);
void	keyab(t_mx *so);
void	keysb(t_mx *so);
void	keydb(t_mx *so);
void	cutnewlineb(t_mx *so);
void	pushimgmapb(t_mx *so);
void	printimgb(t_mx *so, void *pa);
void	initb(t_mx *so);
void	wallintermapb(t_mx *so);
void	pushwallb(t_mx *so);
void	moveplayerb(t_mx *so);
void	initialiserb(t_mx *so);
void	moveplayertoob(t_mx *so);
void	movetfrontb(t_mx *so);
void	cutnewlinetoob(t_mx *so);
void	stringimgb(t_mx *so);
void	conditionsb(t_mx *so);
void	maintoob(t_mx *so);
void	initialisertwob(t_mx *so);
void	moveennemi(t_mx *so);
char	*ft_itoa(int n);
void	animation(t_mx *so);
#endif
