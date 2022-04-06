# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 18:10:03 by akoykka           #+#    #+#              #
#    Updated: 2022/04/06 16:24:04 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



INCLUDES = -I "ft_printf.h" 

CC = gcc

NAME = libftprintf.a

SRCS = ft_printf.c apply_flags.c conversions.c \
		 get_arg.c padding.c utils.c floats.c

FLAGS = -c -Wall -Werror -Wextra
FLAGS += -g

OBJECTS = ft_printf.o apply_flags.o conversions.o \
		 get_arg.o padding.o utils.o floats.o

NAME_TEST = ft_printf_test

all: $(NAME)

$(NAME):
	clear
	@$(CC) $(FLAGS) $(SRCS) $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	
norm:
	norminette $(SRCS)

test:
	gcc -o $(NAME_TEST) main.c -L. -lftprintf -I "ft_printf.h" -L./libft/ -lft

run:
	./$(NAME_TEST)

lldb:
	lldb ./$(NAME_TEST)

