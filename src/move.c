/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:29:32 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/24 00:07:18 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_pass(t_data *d, int tmpx, int tmpy, t_list *list)
{
	t_list	*tmp;

	d->i = 0;
	tmp = list;
	d->move_x = d->x - tmpx;
	d->move_y = d->y - tmpy;
	if (d->move_y < 0 || d->move_x < 0 || d->move_y > d->size_y || PL)
		return (-1);
	while (tmp != NULL)
	{
		if (d->map[d->move_y + tmp->y][d->move_x + tmp->x] == d->player)
		{
			d->i++;
			if (tmp->next != NULL)
				tmp = tmp->next;
		}
		if (d->map[d->move_y + tmp->y][d->move_x + tmp->x] == '.')
			tmp	= tmp->next;
		else
			return (-1);
	}
	if (d->i == 1)
		return (1);
	else
		return (-1);
}

int		ft_pass_list(t_data *d, t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (ft_check_pass(d, tmp->x, tmp->y, list) == 1)
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
	{
		ft_free_list(list);
		return (1);
	}
	ft_free_list(list);
	return (0);
}

void	ft_putmove(t_data *d)
{
	ft_putstr_fd(ft_itoa(d->move_y), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(d->move_x), 1);
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
			if (d->map[i][j] == d->player)
			{
				if (ft_check_case(d, j, i) == 1)
				{
					ft_putmove(d);
					return (1);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_put_lose();
	return (0);
}
