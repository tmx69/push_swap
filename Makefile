# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 18:10:01 by jritchie          #+#    #+#              #
#    Updated: 2019/04/08 10:16:42 by rywisozk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

OBJ = $(patsubst %.c,%.o,$(SRC))

SRC = srcs/push_swap.c \
srcs/oper.c \
srcs/list.c \
srcs/ft_sort.c \
srcs/list2.c \

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	# gcc -g $(FLAGS) -o $(NAME) $^ -L libft -lft -I ./includes -I ./libft
	gcc -g $(FLAGS) srcs/sort.c srcs/push_swap.c srcs/oper.c srcs/oper2.c srcs/oper3.c srcs/algo.c srcs/list.c srcs/alog2.c srcs/ft_sort.c srcs/list2.c -o push_swap libft/libft.a
	gcc -g $(FLAGS) srcs/checker.c srcs/checker2.c srcs/oper.c srcs/oper2.c srcs/oper3.c srcs/list.c srcs/list2.c  -o checker libft/libft.a
%.o: %.c
	gcc $(FLAGS) -c $^ -o $@ -I includes

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
 
re: fclean all