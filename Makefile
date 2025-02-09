
OBJ_GNL = Get_next_line-main/get_next_line.c Get_next_line-main/get_next_line_utils.c 

OBJ = so_long.c actions.c find_positions.c image_functions.c init_prog.c map_check_functions.c map_check_functions2.c \
	map_functions.c free_prog.c

all:
	gcc $(OBJ_GNL) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long

debug:
	gcc $(OBJ_GNL) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o so_long

