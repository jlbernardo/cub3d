# -*- Makefile -*-

NAME	= cub3d

CC		= cc
FLAGS	= -Werror -Wall -Wextra -g3 #-ldl -lglfw -pthread -lm

LIBFT	= ./libft/libft.a
MLX		= ./.MLX42/build/libmlx42.a

INCLUDE	= -I ./libft -I. -I ./.MLX42/include/MLX42/MLX42.h

SDIR	= src/
ODIR	= obj/

SRC		= $(addprefix $(SDIR), cub3d.c)
OBJ		= $(SRC:$(SDIR)%.c=$(ODIR)%.o)

BLU 	=	\033[1;36m
DFL 	=	\033[0m
T_LIB	=	$(shell test -f ./libft/get_next_line.o && echo "yes" 2>&1)

all: libft $(MLX) $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLU) Compiling...$(DFL)"
	@$(CC) $(FLAGS) $(OBJ) $(INCLUDE) $(LIBFT) -o $@
	@echo "$(BLU) All done!$(DFL)"

$(ODIR)%.o:$(SDIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(MLX):
	@cmake -S ./.MLX42 -B ./.MLX42/build
	@cmake --build ./.MLX42/build -j4

libft:
	@if ! [ $(T_LIB) ]; then echo "$(BLU) Creating libft library.$(DFL)";fi
	@make -C libft/ --no-print-directory

clean:
	@make clean -C ./libft --no-print-directory
	@rm -rf $(ODIR)
	@echo "$(BLU) All objects were deleted.$(DFL)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "$(BLU) All binaries were deleted.$(DFL)"

mlxre:
	@cmake --build ./.MLX42/build --clean-first

re: fclean all

reall: fclean mlxre all

.PHONY: all libft clean fclean mlxre re
