/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:10:21 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/04 23:52:49 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(char *str, int arg)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)str;
	i = ft_strlen(str);
	while (i > 0 && p[i] != (unsigned char)arg)
		i--;
	if (p[i] == (unsigned char)arg)
		return ((char *)p + i);
	return (NULL);
}

int	checkexe(char *str)
{
	if (str[1] == 'b' && str[2] == 'e' && str[3] == 'r' && str[4] == '\0')
		return (0);
	return (1);
}

int	checkcaracter(t_mx *so)
{
	so->j = 1;
	so->i = 0;
	while (so->j < so->lenmap - 1)
	{
		so->i = 0;
		while (so->str[so->j][so->i])
		{
			if (so->str[so->j][so->i] != '0' && so->str[so->j][so->i] != '1'
				&& so->str[so->j][so->i] != 'P' && so->str[so->j][so->i] != 'C'
				&& so->str[so->j][so->i] != 'E')
				return (1);
			so->i++;
		}
		so->j++;
	}
	return (0);
}

int	checkcountone(t_mx *so)
{
	so->j = 1;
	so->one = 0;
	so->i = 0;
	while (so->j <= so->lenmap - 2)
	{
		so->i = 0;
		if (so->str[so->j][0] != '1' || so->str[so->j][so->lenline - 1] != '1')
			return (1);
		while (so->str[so->j][so->i])
		{
			if (so->str[so->j][so->i] == '1')
				so->one++;
			so->i++;
		}
		if (so->one == so->lenline)
			return (1);
		else
			so->one = 0;
		so->j++;
	}
	return (0);
}

int	countmap(char *str)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(str, O_RDONLY);
	len = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("map n'existe pas!!!");
		exit(0);
	}
	if (ft_strlen(line) >= 50)
	{
		ft_printf("map is too big\n");
		exit(0);
	}
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}
