NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_A = printf/libftprintf.a

OBJ_PRINTF = printf/ft_writes.c printf/ft_numbers.c printf/ft_hexedecimal.c printf/ft_point.c printf/ft_strlen.c printf/ft_printf.c

OBJ_GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c 

OBJ_SL = so_long.c actions.c find_positions.c condition_image_func.c init_prog.c map_check_functions.c map_check_functions2.c \
	map_functions.c free_prog.c destroy_images.c init_images.c

all: $(NAME)
	
$(NAME): $(OBJ_SL) $(OBJ_PRINTF)
	make -C printf
	$(CC) $(OBJ_GNL) $(OBJ_SL) $(PRINTF_A) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long

clean:
	rm so_long

fclean: clean
	make fclean -C printf

re: fclean all

.PHONY: all clean fclean re
