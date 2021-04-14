#include "cub3d.h"


// void     check_info(t_cube *cube, char *str)
// {
//     if (str[0] == 'R')
//         init_resolution(cube, str);
//     if (str[0] == 'N' && str[1] == 'O')
//         init_texture(cube, &cube->txt_info.NO, str);
//     if (str[0] == 'W' && str[1] == 'E')
//         init_texture(cube, &cube->txt_info.WE, str);
//     if (str[0] == 'S' && str[1] == 'O')
//          init_texture(cube, &cube->txt_info.SO, str);
//     if (str[0] == 'E' && str[1] == 'A')
//         init_texture(cube, &cube->txt_info.EA, str);
//     if (str[0] == 'S' && str[1] != 'O')
//         init_texture(cube, &cube->txt_info.sprite, str);
//     if (str[0] == 'F')
//         init_color(cube, str, &cube->txt_info.col_floor);
//     if (str[0] == 'C')
//         init_color(cube, str, &cube->txt_info.col_ceil);
//     if (cube->all_param == 8)
//         init_map(cube, str);
// }

void        check_info (t_cub3d *cube, char *str)
{
    if (str[0] == 'R')
        init_resolution(cube, str);
}

int     main(int ac, char **av)
{
    t_cub3d cube;
    int fd;
    char *line;

    fd = 0;
    cube.map.all_param = 0;
    if ((fd = open(av[1], O_RDONLY)) == -1)
        return (ft_err(&cube, "File does not exist"));
    while (get_next_line(fd, &line))
    {
        printf("gnl : %s\n", line);
        check_info(&cube, line);
        ft_strdel_gnl(&line);
    }
    printf("need all in order to check map %d", cube.map.all_param);
    close(fd);
    return (0);


}