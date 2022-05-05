# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:32:05 by jamrabhi          #+#    #+#              #
#    Updated: 2022/03/22 18:32:09 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/parsing/exit.c src/parsing/parse_map.c \
	src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c \
	src/parsing/parse_map_utils.c src/game/display.c src/game/move_player.c

OBJ = $(SRC:.c=.o)

INCDIR = include

LIBDIR = libft/

LIB = libft/libft.a

MLXDIR = minilibx-linux/

MLXFLAGS = -lmlx -lXext -lX11

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling Libft ..."
	@cd $(LIBDIR) && make
	@echo "DONE \n"

	@echo "Configuring MiniLibX ..."
	@cd $(MLXDIR) && ./configure > /dev/null 2>&1
	@echo "DONE \n"

	@echo "Compiling So Long ..."
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -lft -L$(MLXDIR) -lmlx_Linux $(MLXFLAGS) -o $(NAME)
	@echo "DONE"

.c.o:
	@${CC} ${CFLAGS} -I$(INCDIR) -I$(LIBDIR) -I$(MLXDIR) -c $< -o $@

clean:
	@echo "Deleting Libft objects files ..."
	@cd $(LIBDIR) && make $@
	@echo "DONE \n"

	@echo "Deleting So Long objects files ..."
	@rm -f $(OBJ)
	@echo "DONE"

fclean: clean

ifneq ("$(shell ls $(MLXDIR)libmlx_Linux.a 2>/dev/null)","")
	@echo "Executing the clean rule of MiniLibX ..."
	@cd $(MLXDIR) && ./configure clean > /dev/null 2>&1
	@echo "DONE \n"
endif

	@echo "Deleting Libft's binary ..."
	@cd $(LIBDIR) && make $@
	@echo "DONE \n"
	
	@echo "Deleting So Long's binary ..."
	@rm -f $(NAME)
	@echo "DONE"

re: fclean all