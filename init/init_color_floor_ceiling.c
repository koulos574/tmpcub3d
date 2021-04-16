#include "../cub3d.h"

static int ft_space(char *str, int i)
{
    while (str[i] == ' ')
        i++;
    while (str[i] == ',')
        i++;
    return (i);
}

void    init_color(t_cube *cube, char *line, t_color *color)
{
    int i;

    i = 1;
    while (line[i])
    {
        if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
        {
            ft_strdel_gnl(&line);
            ft_err(cube, "Color params wrong\n");
        }
        i++;
    }
    i = 1;
    i = ft_space(line, i);
    color->r = ft_atoi(line);
    i = ft_space(line, i);
    color->g = ft_atoi(line);
    i = ft_space(line, i);
    color->b = ft_atoi(line);
    (cube->all_param)++;
}
