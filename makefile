# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 15:02:37 by gverissi          #+#    #+#              #
#    Updated: 2023/10/02 12:52:04 by gverissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address


RM = rm -f

AR = ar -rsc

SRC = pipex.c main.c path_upd.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

	
$(NAME): $(OBJ)
	@make -C ./libft
	@mv ./libft/$(LIBFT) .
	cc -Wall -Wextra -Werror $(OBJ) $(CFLAGS) -L. $(LIBFT) -o $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONE: all clean fclan re