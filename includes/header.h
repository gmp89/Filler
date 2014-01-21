/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:14:42 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/21 23:27:09 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define P1 'O'
# define P2 'X'

# include "libft.h"

typedef struct		s_data
{
	char			*tmp;
	char			player;
	char			**map;
	int				size_x;
	int				size_y;
}					t_data;

int		ft_check_line(char *line, char *str);
char	ft_set_player(char nb);
int		ft_save_map(t_data *d, char **line);
void	ft_print_map(t_data *d);
char	*ft_cpy_n(char *str, int nb);

#endif
