/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 19:20:00 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/23 22:31:04 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_count_stars(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	d->stars = 0;
	while (d->piece[i] != 0)
	{
		while (d->piece[i][j] != 0)
		{
			if (d->piece[i][j] == '*')
				d->stars++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_count_offset(t_data *d)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (d->piece[i] != 0)
	{
		while (d->piece[i][j] != 0)
		{
			if (d->piece[i][j] == '*')
			{
				k = 1;
				break ;
			}
			j++;
		}
		if (k == 1)
			break ;
		j = 0;
		i++;
	}
	d->offset_x = j;
	d->offset_y = i;
}

void	ft_put_lose(void)
{
	ft_putstr_fd("0", 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd("0", 1);
	ft_putstr_fd("\n", 1);
}

char	*ft_cpy_n(char *str, int nb)
{
	char	*tmp;
	int		i;

	i = 0;
	nb -= 1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[nb] != 0)
	{
		tmp[i] = str[nb];
		i++;
		nb++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	ft_print_map(char **map)
{
	int		i;

	i = 0;
	ft_putstr_fd("\n-------tab------\n", 2);
	while (map[i] != 0)
	{
		ft_putstr_fd(map[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	ft_putstr_fd("-------end-tab------\n", 2);
}
