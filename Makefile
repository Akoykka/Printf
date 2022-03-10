# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 18:10:03 by akoykka           #+#    #+#              #
#    Updated: 2022/03/03 22:07:18 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \

NAME = ft_printf

CC = clang

FLAGS = -Wall -Werror -Wextra
FLAGS += -g
 
INCLUDES = -I . -I libft -L libft -lft

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)
clean:

fclean: clean
		
		@rm -f $(NAME)

re: fclean all
