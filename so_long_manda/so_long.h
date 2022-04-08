/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:08:21 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/04 01:48:15 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include<fcntl.h>

char	*ft_strrchr(char *str, int arg);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		checkexe(char *str);
int		countmap(char *str);
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
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img_wall;
	void	*img_zero;
	void	*img_p;
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
}	t_mx;
int		checkfirstlastline(t_mx *so);
int		checkcountone(t_mx *so);
int		countelement(t_mx *so);
int		checkcaracter(t_mx *so);
int		checkline(t_mx *so);
int		checkmap(t_mx *so, char *str);
int		heighone(t_mx *so);
int		checkplayer(t_mx *so);
int		checkcolle(t_mx *so);
int		closewin(int key, t_mx *so);
int		keyhook(int key, t_mx *so);
void	keyw(t_mx *so);
void	keya(t_mx *so);
void	keys(t_mx *so);
void	keyd(t_mx *so);
void	cutnewline(t_mx *so);
void	pushimgmap(t_mx *so);
void	printimg(t_mx *so, void *pa);
void	init(t_mx *so);
void	wallintermap(t_mx *so);
void	pushwall(t_mx *so);
void	moveplayer(t_mx *so);
void	initialiser(t_mx *so);
void	moveplayertoo(t_mx *so);
void	movetfront(t_mx *so);
void	cutnewlinetoo(t_mx *so);
void	stringimg(t_mx *so);
void	conditions(t_mx *so);
void	maintoo(t_mx *so);
void	initialisertwo(t_mx *so);
#endif
