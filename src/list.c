/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 17:06:57 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/23 22:23:26 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

t_list	*ft_add_elem(t_list *list, int x, int y)
{
	t_list	*tmp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (list == NULL)
		return (new);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

t_list	*ft_make_list(t_data *d)
{
	t_list	*list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	list = NULL;
	while (d->piece[i] != 0)
	{
		while (d->piece[i][j] != 0)
		{
			if (d->piece[i][j] == '*')
				list = ft_add_elem(list, j, i);
			j++;
		}
		j = 0;
		i++;
	}
	return (list);
}

void	ft_print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr_fd("\nx :", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd(" y : ", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putstr_fd("\n", 2);
		tmp = tmp->next;
	}
	ft_putstr_fd("----END---", 2);
}
