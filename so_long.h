/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:17:59 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/27 18:59:18 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define  SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include "libft.h"

# if defined (__APPLE__) && (__MACH__)
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define RED_CROSS 17
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define RED_CROSS 33
# endif

# define SUCCESS 0
# define FAILURE 1

# define WIDTH 1000;
# define HEIGHT 1000;

typedef struct s_check
{
	int		read;
	char	*line;
	int		len;
	int		prev_len;
	int		fd;
	int		i;
}	t_check;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		height;
	int		width;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mouv
{
	int	x;
	int	y;
}	t_mouv;

typedef struct s_key
{
	int	a;
	int	w;
	int	s;
	int	d;
}	t_key;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_x_len;
	int		map_y_len;
	int		collect;
	t_key	*key;
	t_mouv	*mouv;
	t_img	*img;
	t_img	tex[5];
	int		counter;
}	t_vars;

/* parser */
t_check	check_is_map(char *av, t_vars *vars);
void	parsing(char *av, t_vars *vars);
/* events */
int		event_loop(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
int		key_hook(int keycode);
void	player_mouv(t_vars *vars);
t_key	*init_key(void);
/* image */
void	pixel_put_color(t_vars *vars, int x, int y, unsigned int color);
void	draw_one_pixe(t_vars *vars, int i, int x_index, int y_index);
void	draw_map(t_vars *vars);
int		check_is_file(char *av, t_vars *vars);
void	draw_player(t_vars *vars);
void	counter_bonus(t_vars *vars);
void	tex_all(t_vars *vars);
/* utils*/
int		__exit__(char *msg, t_vars *vars, int ret);
void	_free_(void *vars);
int		main(int ac, char **av);

#endif
