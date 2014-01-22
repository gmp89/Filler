/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:58:02 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/22 19:21:03 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_save_size_piece(t_data *d, char *tmp)
{
	char	**tab;
	char	*tmp2;
	int		i;

	i = 0;
	tab = ft_strsplit(tmp, ' ');
	d->piece_y = ft_atoi(tab[1]);
	tmp2 = ft_strdup(tab[2]);
	while (tmp2[i] != ':')
		i++;
	tmp2[i] = 0;
	d->piece_x = ft_atoi(tmp2);
	free(tab);
	free(tmp2);
}

void	ft_save_piece(t_data *d, char **line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strdup(*line);
	ft_save_size_piece(d, tmp);
	/* ft_putstr_fd("\n-------------\n", 2);	/\* display *\/ */
	/* ft_putstr_fd("size piece y : ", 2); */
	/* ft_putnbr_fd(d->piece_y, 2); */
	/* ft_putstr_fd(" | size piece x : ", 2); */
	/* ft_putnbr_fd(d->piece_x, 2); */
	/* ft_putstr_fd("\n-------------\n", 2);	/\* end display *\/ */
	d->piece = (char **)malloc(sizeof(char *) * (d->size_y + 1));
	get_next_line(0, line);
	while (j <= d->piece_y)
	{
		tmp = ft_strdup(*line);
		d->piece[j] = (char *)malloc(sizeof(char) * (d->piece_x + 1));
		d->piece[j] = ft_strdup(tmp);
		j++;
		free(tmp);
		if (j == d->piece_y)
			break ;
		get_next_line(0, line);
	}
	d->piece[j] = 0;
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

void	ft_save_size(t_data *d, char *tmp)
{
	char	**tab;
	char	*tmp2;
	int		i;

	i = 0;
	tab = ft_strsplit(tmp, ' ');
	d->size_y = ft_atoi(tab[1]);
	tmp2 = ft_strdup(tab[2]);
	while (tmp2[i] != ':')
		i++;
	tmp2[i] = 0;
	d->size_x = ft_atoi(tmp2);
	free(tab);
	free(tmp2);
}

int		ft_save_map(t_data *d, char **line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 0;
	tmp = ft_strdup(*line);
	ft_save_size(d, tmp);
	get_next_line(0, line);
	get_next_line(0, line);
	tmp = ft_strdup(*line);
	/* ft_putstr_fd("\n-------------\n", 2);	/\* display *\/ */
	/* ft_putstr_fd("size y : ", 2); */
	/* ft_putnbr_fd(d->size_y, 2); */
	/* ft_putstr_fd(" | size x : ", 2); */
	/* ft_putnbr_fd(d->size_x, 2); */
	/* ft_putstr_fd("\n-------------\n", 2);	/\* end display *\/ */
	d->map = (char **)malloc(sizeof(char *) * (d->size_y));
	while (i <= d->size_y)
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
