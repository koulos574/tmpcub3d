NAME = Cub3D

CFLAGS = -Wall -Wextra -Werror  #Missing dans NAME et -c aussi

MINILIBX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

SRC = 	main.c\
		


		init/init_window.c\
		init/init_resolution.c\
		init/init_texture.c\
		init/init_color_floor_ceiling.c\
		init/init_map.c\
		

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
			@gcc -o $(NAME) $(SRC) $(MINILIBX)
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
