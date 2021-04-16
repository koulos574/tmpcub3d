#include "../cub3d.h"

static void check_correct_size_window(t_cube *cube, int i, char *line)
{
    if (line[i])
    {    
        ft_strdel_gnl(&line);
        ft_err(cube, "Too much params, resolution only need 2\n");
    }
    if (cube->mlx.img.widthscreen <= 0 || cube->mlx.img.heightscreen <= 0)
        ft_err(cube, "Resolution need to have a positive W and H");
    if (cube->mlx.img.widthscreen >= 2560)
        cube->mlx.img.widthscreen = 2560;
    if (cube->mlx.img.heightscreen >= 1440)
        cube->mlx.img.heightscreen = 1440;
    init_window(cube);
    (cube->all_param)++;
}

void     init_resolution(t_cube *cub, char *line)
{
    int i;

    i = 1;
    while (line[i])
    {
        if (!ft_isdigit(line[i]) && line[i] != ' ')
        {
            ft_strdel_gnl(&line);
            ft_err(cub, "Resolution params false\n");
        }
        i++;
    }
    i = 1;
    while (line[i] == ' ')
        i++;
    cub->mlx.img.widthscreen = ft_atoi(&line[i]);
    while (ft_isdigit(line[i]))
        i++;
    while (line[i] == ' ')
        i++;
    cub->mlx.img.heightscreen = ft_atoi(&line[i]);
    while (ft_isdigit(line[i]))
        i++;
    check_correct_size_window(cub, i, line);
}