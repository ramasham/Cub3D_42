# include include.mk

# NAME = cub3D
# LIBFT_DIR = ./libft

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -I./include

# OBJS = $(SRCS:.c=.o)

# INCLUDES = -I$(LIBFT_DIR)/include
# LDFLAGS = -lmlx -lXext -lX11 -lm -L$(LIBFT_DIR) -lft
# CFLAGS += $(INCLUDES)

# all: libft $(NAME)

# libft:
# 	@$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(OBJS)
# 	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# clean:
# 	@rm -rf $(OBJS)
# 	@$(MAKE) -C $(LIBFT_DIR) clean

# fclean: clean
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	@rm -rf $(NAME)

# re: fclean all

# .PHONY: all clean fclean re libft

# === Variables ===

NAME        := cub3D

# Directories
SRC_DIR     := src
LIBFT_DIR   := libft
MLX_DIR     := mlx_42
INCLUDE_DIR := include

# Compiler & Flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)

# Linking
LDFLAGS     := -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lm

# Source files
SRCS        := $(shell find $(SRC_DIR) -name "*.c")
OBJS        := $(SRCS:.c=.o)

# === Rules ===

all: $(NAME)

$(NAME): libft mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Build libft
libft:
	@$(MAKE) -C $(LIBFT_DIR)

# Build MiniLibX
mlx:
	@$(MAKE) -C $(MLX_DIR)

# Clean object files
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

# Remove everything
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Recompile everything
re: fclean all

.PHONY: all clean fclean re libft mlx

