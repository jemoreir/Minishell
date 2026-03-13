# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 19:46:58 by lbraga            #+#    #+#              #
#    Updated: 2026/03/05 01:28:47 by lbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
HEADER	=	src/minishell.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.
RM		=	rm -f
OBJ		=	$(SRC:.c=.o)
LIBFT_D	=	src/libft
LIBFT	=	$(LIBFT_D)/libft.a

SRC		=	src/0_debug.c src/0_main.c src/1_data.c src/2_lists.c src/3_exec.c \
			src/4_cmds.c src/5_redirs.c src/6_exit.c

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(NAME) compiled"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_D) --no-print-directory
	
%.o: %.c $(HEADER)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_D) --no-print-directory
	@echo "$(NAME) objects removed"

fclean:
	@$(RM) $(OBJ) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_D) --no-print-directory
	@echo "$(NAME) objects removed"
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re