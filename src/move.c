/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:29:32 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/23 19:11:22 by gpetrov          ###   ########.fr       */
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
	/* ft_putstr_fd("------TEST-----", 2); */
	/* ft_putstr_fd(ft_itoa(d->offset_x), 2); */
	/* ft_putstr_fd(" ", 2); */
	/* ft_putstr_fd(ft_itoa(d->offset_y), 2); */
}

int		ft_check_pass(t_data *d, int tmpx, int tmpy, t_list *list)
{
		t_list	*tmp;
		int		i;

		i = 0;
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp = list;
		/* ft_print_list(tmp); */
		while (tmp != NULL)
		{
			if (i >= 2)
				return (-1);
			if ((d->map[(d->y - tmpy) + tmp->y][(d->x - tmpx) + tmp->x] == d->player || d->map[(d->y - tmpy) + tmp->y][(d->x - tmpx) + tmp->x] == d->player + 32) && i < 2)
			{
				i++;
				d->move_x = d->x - tmpx;
				d->move_y = d->y - tmpy;
				if (tmp->next != NULL)
					tmp = tmp->next;
			}
			if (d->map[(d->y - tmpy) + tmp->y][(d->x - tmpx) + tmp->x] == '.')
					tmp	= tmp->next;
			else
				return (-1);
		}
		return (1);
}

int		ft_pass_list(t_data *d, t_list *list)
{
		t_list	*tmp;

		tmp = (t_list *)malloc(sizeof(t_list));
		tmp = list;
		while (tmp != NULL)
		{
			if (ft_check_pass(d, tmp->x, tmp->y, tmp) == 1)
				return (1);
			else
				tmp = tmp->next;
		}
		return (0);
}

int		ft_check_case(t_data *d, int x, int y)
{
	t_list	*list;
	t_list	*tmp;

	d->x = x;
	d->y = y;
	list = (t_list *)malloc(sizeof(t_list));
	tmp = (t_list *)malloc(sizeof(t_list));
	list = ft_make_list(d);
	tmp = list;
	if (ft_pass_list(d, list) == 1)
		return (1);
	return (0);
}

void	ft_put_lose(void)
{
	ft_putstr_fd("0", 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd("0", 1);
	ft_putstr_fd("\n", 1);
}

int		ft_make_move(t_data *d)
{
	int		i;
	int		j;


	j = 0;
	i = 0;
	while (d->map[i] != 0)
	{
		while (d->map[i][j] != 0)
		{
			if ((d->map[i][j] == d->player || d->map[i][j] == (d->player + 32)))
			{
				if (ft_check_case(d, j, i) == 1)
				{
					if ((d->move_y + d->piece_y) > d->size_y && (d->move_x + d->piece_x) > d->size_x)
					{
						ft_put_lose();
						return (1);
					}
					ft_putstr_fd(ft_itoa(d->move_y), 1);
					ft_putstr_fd(" ", 1);
					ft_putstr_fd(ft_itoa(d->move_x), 1);
					ft_putstr_fd("\n", 1);
					return (1);
				}
			}
			j++;
		}
		j = 0;
		i++;
		/* ft_put_lose(); */
	}
	return (0);
}
