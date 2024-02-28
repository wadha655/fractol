# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wahmed <wahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 11:08:11 by wahmed            #+#    #+#              #
#    Updated: 2023/11/24 13:54:25 by wahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
SRC = main.c extra.c sets.c hooks.c math.c drawing.c parsing.c
	
OBJ = $(SRC:.c=.o)	
CC = cc 

CFLAGS = -Wall -Wextra -Werror 



all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lm -lmlx -framework OpenGL -framework Appkit -o $(NAME)
	
clean: 
	 rm -f $(OBJ)

fclean: clean
	 rm -f $(NAME)
re: fclean all	 