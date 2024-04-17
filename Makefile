# -*- Makefile -*-

NAME	= cub3d

CC		= cc
CFLAG	= -Werror -Wall -Wextra -g3
MFLAG	= -ldl -lglfw -pthread -lm

LIBFT	= ./libft/libft.a
MLX		= ./.MLX42/build/libmlx42.a

INCLUDE	= -I./libft -I. -I./.MLX42/include/MLX42

SDIR	= src/
ODIR	= obj/

SRC		+= $(addprefix $(SDIR), cub3d.c)
SRC		+= $(addprefix $(SDIR)parse/, parse.c get_color.c get_map.c get_texture.c get_player.c)
SRC		+= $(addprefix $(SDIR)draw/, bresenham.c minimap.c raycast_utils.c raycast.c texture.c)
SRC		+= $(addprefix $(SDIR)game/, actions.c game.c mouse_hook.c)
SRC		+= $(addprefix $(SDIR)utils/, conditionals.c initializer.c over.c utils.c)
SRC		+= $(addprefix $(SDIR)validation/, validation.c validation_utils.c)

OBJ		= $(SRC:$(SDIR)%.c=$(ODIR)%.o)

BLU 	=	\033[1;36m
DFL 	=	\033[0m
T_LIB	=	$(shell test -f ./libft/get_next_line.o && echo "yes" 2>&1)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLU) Compiling...$(DFL)"
	@$(CC) $(CFLAG) $(MFLAG) $(OBJ) $(INCLUDE) $(LIBFT) $(MLX) -o $@
	@echo "$(BLU) All done!$(DFL)"

$(ODIR)%.o:$(SDIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

$(MLX):
	@cmake -S ./.MLX42 -B ./.MLX42/build
	@cmake --build ./.MLX42/build -j4

$(LIBFT):
	@if ! [ $(T_LIB) ]; then echo "$(BLU) Creating libft library.$(DFL)";fi
	@make -C libft/ -s --no-print-directory

clean:
	@rm -rf $(ODIR)
	@echo "$(BLU) All objects were deleted.$(DFL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLU) Binary file deleted.$(DFL)"

libclean:
	@rm -f $(LIBFT)
	@make clean -C ./libft -s --no-print-directory

mlxre:
	@cmake --build ./.MLX42/build --clean-first

re: fclean all

reall: fclean libclean mlxre all

.PHONY: all libft clean fclean libclean mlxre re reall
