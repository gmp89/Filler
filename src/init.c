/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:58:02 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/21 22:03:47 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_set_player(char nb)
{
	char	tmp;

	return (tmp = (nb == '1' ? P1 : P2));
}

char	*ft_cpy_n(char *str, int nb)
{
	char	*tmp;
	int		i;

	i = 0;
	nb -= 1;
	tmp = (char *)malloc(sizeof(str));
	while (str[nb] != 0)
	{
		tmp[i] = str[nb];
		i++;
		nb++;
	}
	tmp[i] = 0;
	return (tmp);
}

int		ft_save_map(t_data *d, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	d->size_y = ft_atoi(&line[8]);
	d->size_x = ft_atoi(&line[10]);
	ft_putstr_fd("\n-------------\n", 2);	/* display */
	ft_putstr_fd("size y : ", 2);
	ft_putnbr_fd(d->size_y, 2);
	ft_putstr_fd(" | size x : ", 2);
	ft_putnbr_fd(d->size_x, 2);
	ft_putstr_fd("\n-------------\n", 2);	/* end display */
	d->map = (char **)malloc(sizeof(char *) * (d->size_y));
	while (get_next_line(0, &d->tmp) > 0)
	{
		if (i == 1)
		{
			d->map[j] = (char *)malloc(sizeof(char) * d->size_x);
			d->map[j] = ft_cpy_n(d->tmp, 5);
			ft_putstr_fd("\n<------------->\n", 2);
			ft_putstr_fd(d->map[j], 2);
			ft_putstr_fd("\n", 2);
			j++;
		}
		i++;
	}
	d->map[j] = 0;
	return (0);
}
