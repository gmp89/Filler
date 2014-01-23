/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:14:42 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/23 19:11:14 by gpetrov          ###   ########.fr       */
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
	char			**piece;
	int				size_x;
	int				size_y;
	int				piece_x;
	int				piece_y;
	int				move_x;
	int				move_y;
	int				offset_x;
	int				offset_y;
	int				stars;
	int				tmp_x;
	int				tmp_y;
	int				x;
	int				y;
}					t_data;

typedef struct		s_list
{
	int				x;
	int				y;
	int				chosen;
	struct s_list	*next;
	/* struct s_list	*prev; */
}					t_list;

int		ft_check_line(char *line, char *str);
char	ft_set_player(char nb);
int		ft_save_map(t_data *d, char **line);
void	ft_print_map(char **map);
char	*ft_cpy_n(char *str, int nb);
void	ft_save_piece(t_data *d, char **line);
void	ft_save_size_piece(t_data *d, char *tmp);
int		ft_make_move(t_data *d);
t_list	*ft_make_list(t_data *d);
t_list	*ft_add_elem(t_list *list, int x, int y);
void	ft_count_offset(t_data *d);
int		ft_check_case(t_data *d, int x, int y);
void	ft_print_list(t_list *list);
void	ft_count_stars(t_data *d);
int		ft_pass_list(t_data *d, t_list *list);
int		ft_check_pass(t_data *d, int tmpx, int tmpy, t_list *list);

#endif

/* int		ft_check_case(t_data *d, int x, int y) */
/* { */
/* 	t_list	*list; */
/* 	t_list	*tmp; */
/* 	int		i; */

/* 	i = 0; */
/* 	list = (t_list *)malloc(sizeof(t_list)); */
/* 	tmp = (t_list *)malloc(sizeof(t_list)); */
/* 	list = ft_make_list(d); */
/* 	/\* ft_print_list(list); *\/ */
/* 	/\* ft_putstr_fd("\n --OK-- \n", 2); *\/ */
/* 	tmp = list; */
/* 	ft_count_offset(d); */
/* 	ft_count_stars(d); */
/* 	while (i < d->stars) */
/* 	{ */
/* 		while (tmp != NULL) */
/* 		{ */
/* 			if (d->map[tmp->y + y][tmp->x + x] == '.') */
/* 			{ */
/* 				tmp = tmp->next; */
/* 			} */
/* 			else */
/* 				return (-1); */
/* 		} */
/* 		i++; */
/* 	} */
/* 	free(tmp); */
/* 	free(list); */
/* 	return (1); */
/* } */
