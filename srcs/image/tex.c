/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:11:08 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/27 18:40:26 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define TEX_PLAYER "./tex/knight.xpm"
#define TEX_WALL "./tex/wall.xpm"
#define TEX_COLLECT "./tex/key.xpm"
#define TEX_EXIT "./tex/closed_door.xpm"
#define TEX_ZERO "./tex/floor.xpm"
/*Converts xpm data to a new image instance, and get addr*/
void	set_tex(char *path, t_vars *vars, t_img *tex)
{
	const int	fd = open(path, O_RDONLY);

	if (fd < 0)
		__exit__("path Error\n", vars, FAILURE);
	tex->img = mlx_xpm_file_to_image(vars->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		__exit__("path Error\n", vars, FAILURE);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_len, &tex->endian);
}

void	tex_all(t_vars *vars)
{
	set_tex(TEX_PLAYER, vars, &vars->tex[0]);
	set_tex(TEX_WALL, vars, &vars->tex[1]);
	set_tex(TEX_COLLECT, vars, &vars->tex[2]);
	set_tex(TEX_EXIT, vars, &vars->tex[3]);
	set_tex(TEX_ZERO, vars, &vars->tex[4]);
}
