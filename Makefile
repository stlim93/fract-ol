NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRC_DIR		= src
OBJ_DIR		= obj
MLX_DIR		= ./minilibx-linux

SRCS		= $(SRC_DIR)/*.c
OBJS		= $(SRCS:$(SRC_DIR)/%.o=$(OBJ_DIR)/%.c)

# wtf is this?
MLXFLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES	= -I$(MLX_DIR)

all : libft.a minilibx-linux/libmlx.a $(NAME)

libft.a :
	make -C libft

minilibx-linux/libmlx.a :
	make -C minilibx-linux

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)

clean:
	rm -rf libft/obj/
	rm -rf minilibx-linux/obj/

fclean: clean
	rm fractol
	rm libft/libft.a
	rm minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a

re:		fclean $(NAME)
