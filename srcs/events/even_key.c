/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:07:59 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/27 19:01:12 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == RED_CROSS)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == KEY_W && vars->key->w == 0)
		vars->key->w = 1;
	else if (keycode == KEY_A && vars->key->a == 0)
		vars->key->a = 1;
	else if (keycode == KEY_S && vars->key->s == 0)
		vars->key->s = 1;
	else if (keycode == KEY_D && vars->key->d == 0)
		vars->key->d = 1;
	return (1);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == RED_CROSS)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == KEY_W && vars->key->w == 1)
		vars->key->w = 0;
	else if (keycode == KEY_A && vars->key->a == 1)
		vars->key->a = 0;
	else if (keycode == KEY_S && vars->key->s == 1)
		vars->key->s = 0;
	else if (keycode == KEY_D && vars->key->d == 1)
		vars->key->d = 0;
	return (1);
}

void	print_count(t_vars *vars)
{
	ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
	ft_putstr("\n");
}

void	data_mouv(t_vars *vars)
{
	if (vars->key->w == 1 && vars->map[vars->mouv->y - 1][vars->mouv->x] != '1')
	{
		vars->mouv->y -= 1;
		print_count(vars);
	}
	else if (vars->key->a == 1
		&& vars->map[vars->mouv->y][vars->mouv->x - 1] != '1')
	{
		vars->mouv->x -= 1;
		print_count(vars);
	}
	else if (vars->key->s == 1
		&& vars->map[vars->mouv->y + 1][vars->mouv->x] != '1')
	{
		vars->mouv->y += 1;
		print_count(vars);
	}
	else if (vars->key->d == 1
		&& vars->map[vars->mouv->y][vars->mouv->x + 1] != '1')
	{
		vars->mouv->x += 1;
		print_count(vars);
	}
}

void	player_mouv(t_vars *vars)
{
	if (vars->key->w == 1 || vars->key->a == 1
		|| vars->key->d == 1 || vars->key->s == 1)
	{
		data_mouv(vars);
		if (vars->map[vars->mouv->y][vars->mouv->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->mouv->y][vars->mouv->x] = '0';
		}
	}
}
