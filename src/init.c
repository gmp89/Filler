/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:58:02 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/21 23:26:47 by gpetrov          ###   ########.fr       */
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

void	ft_print_map(t_data *d)
{
	int		i;

	i = 0;
	ft_putstr_fd("\n-------tab------\n", 2);
	while (d->map[i] != 0)
	{
		ft_putstr_fd(d->map[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	ft_putstr_fd("-------end-tab------\n", 2);
}

int		ft_save_map(t_data *d, char **line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 0;
	tmp = ft_strdup(*line);
	d->size_x = 0;
	d->size_y = ft_atoi(&tmp[8]);
	d->size_x = ft_atoi(&tmp[10]);
	get_next_line(0, line);
	get_next_line(0, line);
	tmp = ft_strdup(*line);
	ft_putstr_fd("\n-------------\n", 2);	/* display */
	ft_putstr_fd("size y : ", 2);
	ft_putnbr_fd(d->size_y, 2);
	ft_putstr_fd(" | size x : ", 2);
	ft_putnbr_fd(d->size_x, 2);
	ft_putstr_fd("\n-------------\n", 2);	/* end display */
	d->map = (char **)malloc(sizeof(char *) * (d->size_y));
	get_next_line(0, line);
	while (i < d->size_y)
	{
		tmp = ft_strdup(*line);
		d->map[j] = (char *)malloc(sizeof(char) * (d->size_x + 1));
		d->map[j] = ft_cpy_n(tmp, 5);
		j++;
		i++;
		get_next_line(0, line);
		free(tmp);
	}
	d->map[j] = 0;
	return (0);
}
