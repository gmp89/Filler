/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:11:22 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/22 19:56:29 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_line(char *line, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[j] != 0)
	{
		if (str[i] == line[j])
			i++;
		if (str[i] == 0)
			return (1);
		j++;
	}
	return (-1);
}

int		main(void)
{
	t_data	d;
	char	*line;

	while ((get_next_line(0, &line) > 0))
	{
		if (ft_check_line(line, "$$$") == 1)
		{
			d.player = (line[10] == '1' ? P1 : P2);
			/* ft_putstr_fd("\n-------------\n", 2); */
			/* ft_putchar_fd(d.player, 2); */
			/* ft_putstr_fd("\n-------------\n", 2); */
		}
		if (ft_check_line(line, "Plateau") == 1)
		{
			ft_save_map(&d, &line);
			ft_print_map(d.map);
		}
		if (ft_check_line(line, "Piece") == 1)
		{
			ft_save_piece(&d, &line);
			/* ft_putstr_fd("\n --OK-- \n", 2); */
			ft_print_map(d.piece);
			ft_make_move(&d);
			/* ft_putstr_fd("1 1\n", 1); */
		}
	}
	return (0);
}
