# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 15:30:51 by pivanovi          #+#    #+#              #
#    Updated: 2016/01/07 17:35:05 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =			srcs/get_next_line.c	\
				srcs/operations.c		\
				srcs/is_ordered.c		\
				srcs/is_number.c		\
				srcs/char_list.c		\
				srcs/process.c			\
				srcs/execute.c			\
				srcs/list.c

SRCS_CHECKER =	srcs_checker/checker.c

SRCS_PS =		srcs_ps/push_swap.c

OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
OBJS_PS = $(SRCS_PS:.c=.o)

CFLAGS += -I./includes

all: checker push_swap

checker: $(OBJS) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_CHECKER) libft/libft.a -o $@

push_swap: $(OBJS) $(OBJS_PS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_PS) libft/libft.a -o $@

clean:
	/bin/rm -f $(OBJS) $(OBJS_CHECKER) $(OBJS_PS)

fclean: clean
	/bin/rm -f checker push_swap

re: fclean all

