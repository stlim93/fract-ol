NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRC_DIR		= src
OBJ_DIR		= obj
MLX_DIR		= ./minilibx-linux

# Fractol files
SRCS		= $(SRC_DIR)/*.c
FILES := $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# MINILIB folders
MLXFLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES	= -I$(MLX_DIR)

all : libft/libft.a minilibx-linux/libmlx.a $(NAME)

libft/libft.a :
	make -C libft

minilibx-linux/libmlx.a :
	make -C minilibx-linux

$(NAME) : libft/libft.a minilibx-linux/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)

clean:
	rm -rf libft/obj/ minilibx-linux/obj/ obj/

fclean: clean
	rm $(NAME) libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a

re:		fclean $(NAME)

.PHONY: all clean fclean re
