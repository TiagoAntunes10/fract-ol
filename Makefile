PRE = ./
INCLUDE = ./Include
FUNCTION = ./libft
MLX = ./minilibx-linux
BONUS = ./bonus/

SOURCE = fractol.c errors.c ft_atod.c mlx_utils.c mlx_hooks.c \
		utils.c mandel.c julia.c

SOURCE_BON = fractol_bonus.c errors_bonus.c ft_atod.c mlx_utils.c mlx_hooks.c \
		utils.c mandel_bonus.c julia_bonus.c utils_bonus.c tricorn.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}
SOURCES_BON = ${addprefix $(PRE), $(SOURCE_BON)}

NAME = fractol
NAME_BONUS = fractol_bonus
LIB = $(FUNCTION)/libftprintf.a
MLX_COM = $(MLX)/libmlx.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g 
MLX_FLAGS = -lm -lz -lXext -lX11

OBJ = $(SOURCES:.c=.o)
OBJ_BON = $(SOURCES_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX_COM)
	cc $(FLAGS) -o $@ $^ $(MLX_FLAGS)

$(LIB):
	$(MAKE) -C $(FUNCTION)

$(MLX_COM):
	$(MAKE) -C $(MLX)

.c.o:
		$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BON) $(LIB) $(MLX_COM)
	cc $(FLAGS) -o $@ $^ $(MLX_FLAGS)

.c.o2:
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ) $(OBJ_BON)
	$(MAKE) clean -C $(FUNCTION)
	$(MAKE) clean -C $(MLX)
        
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(FUNCTION)
	$(MAKE) fclean -C $(MLX)

re: fclean all
