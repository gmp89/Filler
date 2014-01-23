#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/21 16:14:59 by gpetrov           #+#    #+#              #
#    Updated: 2014/01/23 18:49:56 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= filler
FILES	= main.c init.c move.c list.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft

all: $(NAME)
$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
.obj/%.o: src/%.c
	mkdir -p .obj
	cc -c $< -o $@ $(FLAGS) $(INC)
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	gdb $(NAME)
exec:
	~/ruby-2.1.0/bin/./ruby vm_beta.rb -f maps/map1.map -p1 \
	~/Rendu/Algorithmie/filler/bin/grati.filler -p2 \
	~/Rendu/Algorithmie/filler/filler
clean:
	rm -rf .obj
fclean: clean
	rm -f $(NAME)
re: fclean all
