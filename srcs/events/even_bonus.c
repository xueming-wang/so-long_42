/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:14:57 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/27 19:01:23 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_key	*init_key(void)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (!key)
		return (NULL);
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	return (key);
}

void	counter_bonus(t_vars *vars)
{
	const char	*str;

	str = ft_itoa(vars->counter);
	if (!str)
		__exit__(NULL, vars, FAILURE);
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0xFF0000, (char *)str);
	free((char *)str);
}

static int	key_event(t_vars *vars)
{
	if (vars->collect == 0 && vars->map[vars->mouv->y][vars->mouv->x] == 'E')
		__exit__("YOU ARE WIN\n", vars, SUCCESS);
	else
		player_mouv(vars);
	return (1);
}

int	event_loop(t_vars *vars)
{
	draw_map(vars);
	draw_player(vars);
	key_event(vars);
	if (BONUS)
		counter_bonus(vars);
	return (1);
}
