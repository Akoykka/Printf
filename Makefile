# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 18:10:03 by akoykka           #+#    #+#              #
#    Updated: 2022/04/02 17:36:26 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_TEST = main.c apply_flags.c conversions.c \
		apply_flags_s.c get_arg.c padding.c utils.c

NAME_TEST = ft_printf_test

CC_TEST = gcc

FLAGS_TEST = -Wall -Werror -Wextra
FLAGS_TEST += -g

INCLUDES_TEST = -I . -I libft -L libft -lft

INCLUDES_ = "ft_printf.h"

NAME = libftprintf.a

SRCS = ft_printf.c apply_flags.c conversions.c \
		apply_flags_s.c get_arg.c padding.c utils.c


OBJECTS = ft_printf.o apply_flags.o conversions.o \
		apply_flags_s.o get_arg.o padding.o utils.o

INCLUDES = "ft_printf.h"


all: $(NAME)

all1: $(NAME_TEST)

$(NAME_TEST):
	clear
	$(CC_TEST) $(FLAGS_TEST) $(SRCS_TEST) $(INCLUDES_TEST) -o $(NAME_TEST)
clean1:

fclean1: clean1

	@rm -f $(NAME_TEST)

re1: fclean1 all1

run:
	./$(NAME_TEST)
lldb:
	lldb ./$(NAME_TEST)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRCS) -I $(INCLUDES)
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
	./printf_test/run.sh