NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX = ./MLX42
LIBFT = ./libft

HEADERS = -I ./inc -I $(LIBMLX)/include/MLX42 -I $(LIBFT)
LIBS = $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" 

SRCS = src/main.c\
	src/map_check.c\
	src/map_check2.c\
	src/map_check3.c\
	src/map.c\
	src/move.c\
	src/move2.c\
	src/move3.c\
	src/visual.c\

BONUS = src_bonus/main_bonus.c\
	src_bonus/map_check_bonus.c\
	src_bonus/map_check2_bonus.c\
	src_bonus/map_check3_bonus.c\
	src_bonus/map_bonus.c\
	src_bonus/move_bonus.c\
	src_bonus/move2_bonus.c\
	src_bonus/move3_bonus.c\
	src_bonus/visual_bonus.c\
	src_bonus/visual_2_bonus.c\
	src_bonus/enemy_bonus.c\
	src_bonus/move_enemy_bonus.c\
	src_bonus/move_enemy_bonus2.c\
	src_bonus/move_enemy_bonus3.c\

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"
	
$(NAME): $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/libmlx.a
	@$(CC) -g $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(LIBMLX)/libmlx.a:
	@make -C $(LIBMLX)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)/libft.a $(LIBMLX)/libmlx.a
	@$(CC) -g $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@make -C $(LIBFT) clean
	@make -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT) fclean
	@make -C $(LIBMLX) clean

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
