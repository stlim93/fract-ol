# Compiler and flags
CC 				= 		cc
CFLAGS			= 		-Wall -Werror -Wextra
RM				= 		rm -f

# Libft
LIBFT_SRC_DIR	:=		src/libft
LIBFT_OBJ_DIR	:=		obj/libft

# Printf
PRINTFT_SRC_DIR	:=		src/ft_printf
PRINTFT_OBJ_DIR	:=		obj/ft_printf

# GNL
GNL_SRC_DIR		:=		src/get_next_line
GNL_OBJ_DIR		:=		obj/get_next_line

# Source files
LIBFT_FILES := $(wildcard $(LIBFT_SRC_DIR)/*.c)
PRINTFT_FILES := $(wildcard $(PRINTFT_SRC_DIR)/*.c)
GNL_FILES := $(wildcard $(GNL_SRC_DIR)/*.c)

# To convert all c files to object files
LIBFT_OBJS = $(patsubst $(LIBFT_SRC_DIR)/%.c, $(LIBFT_OBJ_DIR)/%.o, $(LIBFT_FILES))
PRINTFT_OBJS = $(patsubst $(PRINTFT_SRC_DIR)/%.c, $(PRINTFT_OBJ_DIR)/%.o, $(PRINTFT_FILES))
GNL_OBJS = $(patsubst $(GNL_SRC_DIR)/%.c, $(GNL_OBJ_DIR)/%.o, $(GNL_FILES))

$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTFT_OBJ_DIR)/%.o: $(PRINTFT_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_OBJ_DIR)/%.o: $(GNL_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	
NAME = libft.a

all: 		$(NAME)

$(NAME):	$(LIBFT_OBJS) $(PRINTFT_OBJS) $(GNL_OBJS)
			ar rcs $(NAME) $(LIBFT_OBJS)
			ar rcs $(NAME) $(PRINTFT_OBJS)
			ar rcs $(NAME) $(GNL_OBJS)

clean:
			$(RM) $(LIBFT_OBJS) $(PRINTFT_OBJS) $(GNL_OBJS)

fclean: 	clean
			$(RM) $(NAME) $(LIBFT_OBJS) $(PRINTFT_OBJS) $(GNL_OBJS)

re:			fclean $(NAME)