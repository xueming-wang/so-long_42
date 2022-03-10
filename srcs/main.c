/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:04:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/27 16:30:20 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event_quit(t_vars *vars)
{
	__exit__(NULL, vars, SUCCESS);
	return (0);
}

static void	__mlx__(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->win = mlx_new_window(vars->mlx, 1000, 1000, "so_long");
	if (!vars->win)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->img->img = mlx_new_image(vars->mlx, 1000, 1000);
	if (!vars->img->img)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	tex_all(vars);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel,
			&vars->img->line_len, &vars->img->endian);
	vars->img->width = WIDTH;
	vars->img->height = HEIGHT;
	vars->counter = 0;
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, RED_CROSS, 1L << 2, event_quit, vars);
	mlx_loop_hook(vars->mlx, event_loop, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac < 2 || ac > 2)
		__exit__("Error\nargument Error\n", NULL, FAILURE);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->mouv = malloc(sizeof(t_mouv));
	if (!vars->mouv)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	vars->key = init_key();
	if (!vars->key)
		__exit__("Error\nmalloc Error \n", vars, FAILURE);
	parsing(av[1], vars);
	__mlx__(vars);
	return (SUCCESS);
}
