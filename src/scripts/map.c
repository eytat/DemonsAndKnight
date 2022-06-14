/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:12:03 by amateo-r          #+#    #+#             */
/*   Updated: 2021/11/08 17:12:07 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libsl.h"

/**
 * Inicialize elements of param 'map' and allocs memory.
 * @param	char	*fn		File direction.
 * @param	t_map	*map	Data of filename.map.
 */
void	init_map(int row, int col, t_map *map)
{
	int		i;

	map->row = row;
	map->col = col;
	map->board = (char **) malloc(row * sizeof(char *));
	i = -1;
	while (++i < row)
		map->board[i] = (char *) malloc(col * sizeof(char));
	return ;
}

/**
 * Iniciliaze param 'map' and fill it with characters of
 * direction 'fn'.
 * @param	char	*fn		Filename.ber direction.
 * @param	t_map	*map	Data of filename.map.
 */
void	get_map(char *fn, t_var *var)
{
	int		fd;
	int		x;
	int		y;
	char	c;

	init_map(ft_rows(fn), ft_columns(fn), &var->map);
	fd = open(fn, O_RDONLY);
	x = 0;
	y = 0;
	while (read(fd, &c, 1))
	{
		if (c != '\n')
		{
			var->map.board[x][y] = c;
			y++;
		}
		else
		{
			x++;
			y = 0;
		}
	}
	close(fd);
	return ;
}

/**
 * Starts a window and place all the tile elements based on
 * matrix 'map'.
 * @param	t_var	*var	All data about the game.
 */
void	init_window(char *fn, t_var *var)
{
	int	width;
	int	height;

	width = 100;
	height = 100;
	var->mlx = mlx_init();
	var->mlx_win = mlx_new_window(var->mlx, width * ft_columns(fn), \
	height * ft_rows(fn), "So Long");
	var->wall.img = mlx_xpm_file_to_image(var->mlx, W_PATH, \
	&width, &height);
	var->space.img = mlx_xpm_file_to_image(var->mlx, SP_PATH, \
	&width, &height);
	var->door.img = mlx_xpm_file_to_image(var->mlx, EX_PATH, \
	&width, &height);
	var->wall.addr = mlx_get_data_addr(var->wall.img, &var->wall.bpp, \
	&var->wall.line_length, &var->wall.endian);
	var->space.addr = mlx_get_data_addr(var->space.img, \
	&var->space.bpp, &var->space.line_length, &var->space.endian);
	var->door.addr = mlx_get_data_addr(var->door.img, \
	&var->door.bpp, &var->door.line_length, &var->door.endian);
	return ;
}

/**
 * Put a tile into window base coordinates.
 * @param	int		x	Coordinate for axis X.
 * @param	int		y	Coordinate for axis Y.
 * @param	t_var	var	Program data.
 */
void	put_tile(int x, int y, t_var *var)
{
	if (var->map.board[x][y] == MWA)
		mlx_put_image_to_window(var->mlx, var->mlx_win, \
		var->wall.img, y * ST, x * ST);
	else if (var->map.board[x][y] == MSP)
		mlx_put_image_to_window(var->mlx, var->mlx_win, \
		var->space.img, y * ST, x * ST);
	else if (var->map.board[x][y] == MEN)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_win, \
		var->enemy.c_img.img, y * ST, x * ST);
		var->nenemies++;
	}
	else if (var->map.board[x][y] == MST)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_win, \
		var->player.c_img.img, y * ST, x * ST);
		var->player.pos.x = x;
		var->player.pos.y = y;
	}
	else if (var->map.board[x][y] == MEX)
		mlx_put_image_to_window(var->mlx, var->mlx_win, \
		var->door.img, y * ST, x * ST);
	return ;
}

/**
 * Build map in funciton of filename.ber data. Also give images to 
 * players and enemies.
 * @param	t_var	*var	All mayor data about the game and map.
 */
void	build_map(t_var *var)
{
	int	x;
	int	y;
	int	width;
	int	height;

	var->nenemies = 0;
	var->player.nmoves = 0;
	width = 100;
	height = 100;
	var->player.c_img.img = mlx_xpm_file_to_image(var->mlx, P_PATH, \
	&width, &height);
	var->enemy.c_img.img = mlx_xpm_file_to_image(var->mlx, E_PATH, \
	&width, &height);
	x = -1;
	while (++x < var->map.row)
	{
		y = -1;
		while (++y < var->map.col)
			put_tile(x, y, var);
	}
	return ;
}
