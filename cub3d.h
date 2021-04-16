#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include <math.h>


#include <stdio.h>





#define path_flag 5

typedef struct  s_texture {
    void        *img_file;
    char        *addr;
    int         width;
    int         height;      
    int         bpp;
    int         size_line;  
    int         endian;
}               t_texture;

typedef struct  s_mlx_img 
{
    void        *image;
    void        *ptr;
    char        *addr;
    int         bpp;
    int         line_length;
    int         endian;
	int    	 	widthscreen;
    int     	heightscreen;
}               t_mlx_img;

typedef struct  s_color_f_and_c
{
    int         r;
    int         g;
    int         b;
    int         color;
}               t_color;


typedef struct t_texture_info
{
    t_texture   NO;
    t_texture   SO;
    t_texture   WE;
    t_texture   EA;
    t_texture   sprite;
    t_color     col_ceil;
    t_color     col_floor;
}               t_txt_info;


typedef struct s_mlx {
    void        *ptr;
    void        *win;
    t_mlx_img   img;
}               t_mlx;

typedef struct  s_cub3d {
    t_mlx       mlx;
    t_txt_info  txt_info;  
    int         all_param;   
}               t_cube;


/*
**  init folder
*/

/*
**  init_resolution
*/
void    init_resolution(t_cube *cub, char *line);
void    init_texture(t_cube *cube, t_texture *txt, char *line); 
void    init_window(t_cube *cube);
void    init_color(t_cube *cube, char *line, t_color *color);
void    init_map(t_cube *cube, char *str);

// void    init_texture(t_cub *cube, char *texture, char *line);

/*
**  main.c
*/

void     check_info(t_cube *cub, char *str);

/*
**  ft_err.c
*/

int     ft_err(t_cube *cub, char *error);
