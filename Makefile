# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:06:26 by anfouger          #+#    #+#              #
#    Updated: 2025/11/06 14:40:58 by anfouger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl_test
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=32

SRC = main.c get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re