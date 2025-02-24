NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_GNL = Get_next_line-main/get_next_line.c Get_next_line-main/get_next_line_utils.c 

OBJ_SL = so_long.c actions.c find_positions.c condition_image_func.c init_prog.c map_check_functions.c map_check_functions2.c \
	map_functions.c free_prog.c destroy_images.c init_images.c

all: $(NAME)
	
$(NAME): $(OBJ_SL)
	$(CC) $(OBJ_GNL) $(OBJ_SL) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -fsanitize=address -g -o so_long
	make -C printf

clean:
	rm so_long

fclean: clean
	make fclean -C printf

re: fclean all

.PHONY: all clean fclean re
