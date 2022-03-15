# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 18:10:03 by akoykka           #+#    #+#              #
#    Updated: 2022/03/15 10:43:09 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c flags.c utils.c apply_flags_di.c conversions.c \
		apply_flags_s.c

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

run:
	./$(NAME)
