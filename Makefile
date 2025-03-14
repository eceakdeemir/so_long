NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_A = printf/libftprintf.a

OBJ_PRINTF = printf/ft_writes.c printf/ft_numbers.c printf/ft_hexedecimal.c printf/ft_point.c printf/ft_strlen.c printf/ft_printf.c

OBJ_GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c 

OBJ_SL = so_long.c actions.c find_positions.c condition_image_func.c init_prog.c map_check_functions.c map_check_functions2.c \
	map_functions.c free_prog.c destroy_images.c init_images.c ft_itoa.c

BONUS_OBJ_SL = so_long_bonus.c actions_bonus.c find_positions_bonus.c condition_image_functions_bonus.c init_prog_bonus.c \
	map_check_functions_bonus.c map_check_functions2_bonus.c \
	map_functions_bonus.c free_prog_bonus.c destroy_images_bonus.c init_images_bonus.c ft_itoa_bonus.c

all: $(NAME)
	
$(NAME): $(OBJ_SL) $(OBJ_PRINTF)
	make -C printf
	$(CC) $(OBJ_GNL) $(OBJ_SL) $(PRINTF_A) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long



bonus: $(NAME_BONUS)
$(NAME_BONUS): $(BONUS_OBJ_SL) $(OBJ_PRINTF)
	make -C printf
	$(CC) $(OBJ_GNL) $(BONUS_OBJ_SL) $(PRINTF_A) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long_bonus


clean:
	rm so_long so_long_bonus

fclean: clean
	make fclean -C printf

re: fclean all

.PHONY: all clean fclean re bonus
