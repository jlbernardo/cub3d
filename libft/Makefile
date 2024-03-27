# -*- Makefile -*-

NAME = libft.a

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3 -I.

SRC = ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c \
				ft_isprint.c	ft_tolower.c	ft_toupper.c	ft_atoi.c \
				ft_memcmp.c		ft_strncmp.c	ft_itoa.c		ft_strdup.c \
				ft_split.c		ft_strchr.c		ft_strrchr.c	ft_strjoin.c \
				ft_strtrim.c	ft_strmapi.c	ft_substr.c		ft_strnstr.c \
				ft_bzero.c		ft_putnbr_fd.c	ft_putchar_fd.c	ft_putstr_fd.c \
				ft_putendl_fd.c	ft_memset.c		ft_calloc.c		ft_memchr.c \
				ft_memcpy.c		ft_memmove.c	ft_striteri.c	ft_strlen.c \
				ft_strlcpy.c	ft_strlcat.c	ft_lstsize_bonus.c				ft_lstlast_bonus.c ft_atol.c\
				ft_lstnew_bonus.c				ft_lstmap_bonus.c \
				ft_lstdelone_bonus.c			ft_lstclear_bonus.c \
				ft_lstiter_bonus.c				ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c	ft_printf.c	get_next_line.c

SRC += $(addprefix printf_utils/, ft_handle_char.c ft_handle_int.c ft_handle_lower_hex.c ft_handle_octothorpe.c ft_handle_percent.c ft_handle_plus.c ft_handle_ptr.c ft_handle_space.c ft_handle_str.c ft_handle_unsigned_int.c ft_handle_upper_hex.c)

OBJ = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@ar -rcs $(NAME) $< -o $@

$(NAME): $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
