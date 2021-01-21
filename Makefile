# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 16:20:44 by atomatoe          #+#    #+#              #
#    Updated: 2021/01/20 16:55:52 by atomatoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ./main/deque.cpp ./main/list.cpp ./main/queue.cpp ./main/stack.cpp ./main/vector.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(OBJS)
		clang++  $(CFLAGS) ./main/deque.cpp -o deque_test
		clang++  $(CFLAGS) ./main/list.cpp -o list_test
		clang++  $(CFLAGS) ./main/queue.cpp -o queue_test
		clang++  $(CFLAGS) ./main/stack.cpp -o stack_test
		clang++  $(CFLAGS) ./main/vector.cpp -o vector_test

clean:
		rm -rf $(OBJS)
		rm -rf deque_test list_test queue_test stack_test vector_test

fclean: clean

re: fclean all

.PHONY: all clean fclean re