# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 18:10:03 by akoykka           #+#    #+#              #
#    Updated: 2022/04/18 19:52:30 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I "ft_printf.h"

CC = gcc

NAME = libftprintf.a

SRCS = ft_printf.c apply_flags.c apply_flags2.c conversions.c csp_conversions.c\
		rounding.c get_arg.c padding.c utils.c floats.c makestruct.c\
		libft/ft_atoi.c libft/ft_isdigit.c libft/ft_itoa.c \
		libft/ft_memalloc.c libft/ft_memmove.c libft/ft_memset.c \
		libft/ft_putstr.c libft/ft_strchr.c libft/ft_strcpy.c \
		libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strndup.c \
		libft/ft_strnew.c libft/ft_strstr.c libft/ft_toupper.c \
		libft/ft_strncpy.c libft/ft_strcat.c libft/ft_strdup.c \
		libft/ft_strdel.c

FLAGS = -c -Wall -Werror -Wextra

OBJECTS = ft_printf.o apply_flags.o conversions.o csp_conversions.o rounding.o \
		get_arg.o padding.o utils.o apply_flags2.o floats.o makestruct.o \
		ft_atoi.o ft_isdigit.o ft_itoa.o \
		ft_memalloc.o ft_memmove.o ft_memset.o \
		ft_putstr.o ft_strchr.o ft_strcpy.o \
		ft_strjoin.o ft_strlen.o ft_strndup.o \
		ft_strnew.o ft_strstr.o ft_toupper.o \
		ft_strncpy.o ft_strcat.o ft_strdup.o ft_strdel.o

NAME_TEST = ft_printf_test

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) $(SRCS) $(INCLUDES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all

norm:
	norminette $(SRCS)

test:
	gcc -g -o $(NAME_TEST) main.c -L. -lftprintf -I "ft_printf.h"
test1:
	gcc  -o $(NAME_TEST) main.c -L. -lftprintf -I "ft_printf.h" -L./libft/ -lft

run:
	./$(NAME_TEST)

lldb:
	lldb ./$(NAME_TEST)

dotest:
	./printf_test/run.sh

test42:
	bash ~/workspace/42FileChecker/42FileChecker.sh