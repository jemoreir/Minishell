# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 09:29:19 by jemoreir          #+#    #+#              #
#    Updated: 2026/02/12 09:29:19 by jemoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = mini
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft
LDFLAGS = -lreadline

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/main.c src/prints.c src/parse.c src/token.c src/lexer.c \
		src/helpers.c src/handlers.c src/free.c src/tester.c \
		src/expansions.c
OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(NAME) 
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all
