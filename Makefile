# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:26:42 by pterekho          #+#    #+#              #
#    Updated: 2024/05/30 17:26:42 by pterekho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex
CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

HEADER 	= pipex.h

SRC = pipex.c errors.c execs.c ./libft/ft_putstr_fd.c \
		./libft/ft_split.c ./libft/ft_strjoin.c \
		./libft/ft_strlen.c ./libft/ft_strnstr.c \
		./libft/ft_substr.c ./libft/ft_strchr.c 
		
OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re, clean, fclean, all