/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:29:32 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/22 20:29:40 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int		ft_check_case(t_data *d, int x, int y)
{
	t_list	*list;
	t_list	*tmp;

	list = (t_list *)malloc(sizeof(t_list));
	tmp = (t_list *)malloc(sizeof(t_list));
	list = ft_make_list(d);
	/* ft_print_list(list); */
	ft_putstr_fd("\n --OK-- \n", 2);
	tmp = list;
	ft_count_offset(d);
	tmp->x += x;
	tmp->y += y;
	tmp = tmp->next;

	while (tmp != NULL)
	{
		tmp->x += x;
		tmp->y += y;
		if (d->map[tmp->y][tmp->x] == '.')
		{
			/* d->move_x -= d->offset_x; */
			/* d->move_y -= d->offset_y; */
			tmp = tmp->next;
		}
		else
			return (-1);
	}
	free(list);
	return (1);
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
			if (d->map[i][j] == d->player || d->map[i][j] == (d->player + 32))
			{
				if (ft_check_case(d, j, i) == 1)
				{
					ft_putstr_fd("1 1\n", 1);
					/* ft_putnbr(d->move_y); */
					/* ft_putchar(' '); */
					/* ft_putnbr(d->move_x); */
					/* ft_putchar('\n'); */
					return (1);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
