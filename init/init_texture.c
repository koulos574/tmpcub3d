#include "../cub3d.h"

void    init_texture(t_cube *cube, t_texture *txt, char *line)
{
    int i;
    
    i = 2;
    while (line[i] == ' ')
        i++;
    if (!(txt->img_file = mlx_xpm_file_to_image(cube->mlx.ptr, &line[i], &(txt->width), &(txt->height))))
    {
        ft_strdel_gnl(&line);
        ft_err(cube, "Wrong path for textures");
    }
    txt->addr = mlx_get_data_addr(txt->img_file, &(txt->bpp), &(txt->size_line), &(txt->endian));
    (cube->all_param)++;
}