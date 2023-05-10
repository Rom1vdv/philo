# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 15:04:59 by romvan-d          #+#    #+#              #
#    Updated: 2023/05/08 17:04:25 by romvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FILES = init_philos main parsing

UTILS_FILES = destroy_philos my_atoi timestamp

SRCS = $(addprefix utils/, $(addsuffix .c, $(UTILS_FILES))) \
	$(addprefix sources/, $(addsuffix .c, $(FILES)))

OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./includes


$(NAME): $(OBJS)
		$(CC) $(SANITIZE) $(CFLAGS) -o $@ $(OBJS)

all:    $(NAME)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME) $(MLX)
		
re: fclean all

.PHONY: all clean fclean re