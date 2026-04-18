NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRC_DIR		= src
OBJ_DIR		= obj
MLX_DIR		= ./minilibx-linux

SRCS		= $(SRC_DIR)/main.c
OBJS		= $(SRCS:$(SRC_DIR)/%.o=$(OBJ_DIR)/%.c)

# wtf is this?
MLXFLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES	= -I$(MLX_DIR)

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
