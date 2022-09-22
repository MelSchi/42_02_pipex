# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:36:53 by mschiman          #+#    #+#              #
#    Updated: 2022/02/08 15:18:39 by mschiman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = pipex

MAIN = ./src/main.c

MAIN_BONUS = ./src/bonus_main.c \

SOURCES = 	./src/get_valid_path.c \
			./src/get_excecve_param.c \
			./src/open_files.c \
			./src/pipes.c \
			./src/errors.c \
			./src/exits.c \
			./src/pipex.c \
			./src/ft_strjoin_gnl.c \
			./src/get_next_line.c 

OBJS = ${SOURCES:.c=.o}

LIBFT = libft
LIBFT_NAME = libft.a

$(NAME) : $(SOURCES)
	@make  -C ./libft
	@make  bonus -C ./libft
	$(CC) $(CFLAGS) $(MAIN) $(SOURCES) -L$(LIBFT) -lft -o $(NAME)

all: $(NAME)

bonus: $(SOURCES)
	@make  -C ./libft
	@make  bonus -C ./libft
	$(CC) $(CFLAGS) $(MAIN_BONUS) $(SOURCES) -L$(LIBFT) -lft -o $(NAME)

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean : clean
	@make fclean -C ./libft
	@rm -f ${NAME}

re:	fclean all

re_bonus: fclean bonus

.PHONY: clean fclean re re_bonus