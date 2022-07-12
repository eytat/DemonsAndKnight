/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:25:57 by amateo-r          #+#    #+#             */
/*   Updated: 2021/12/15 18:26:00 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libsl.h"

void	update_pos(int x, int y, t_var *var);
void	update_win(int mx, int my, t_var *var);
void	move_pc(int x, int y, t_var *var);

/**
 * DESCRIPTION:
 * Change data of map.
 * PARAMETERS:
 * @param	int		x	Pixel modification of Y axis in map.
 * @param	int		y	Pixel modification of X axis in map.
 * @param	t_var	var	Data about game.
 */
void	update_pos(int x, int y, t_var *var)
{
	var->map.board[var->player.pos.x + x][var->player.pos.y + y] = 'P';
	var->map.board[var->player.pos.x][var->player.pos.y] = '0';
	var->player.pos.x += x;
	var->player.pos.y += y;
	var->player.nmoves += 1;
	return ;
}

/**
 * DESCRIPTION:
 * Put the new images into the window.
 * PARAMETERS:
 * @param	int		mx	Pixel modification of Y axis.
 * @param	int		my	Pixel modification of X axis.
 * @param	t_var	var	Data about game.
 */
void	update_win(int mx, int my, t_var *var)
{
	int	w;
	int	h;

	w = 100;
	h = 100;
	mlx_destroy_image(var->mlx, var->player.c_img.img);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->space.img, \
	var->player.pos.y * ST, var->player.pos.x * ST);
	var->player.c_img.img = mlx_xpm_file_to_image(var->mlx, P_PATH, &w, &h);
	mlx_put_image_to_window(var->mlx, var->mlx_win, \
	var->player.c_img.img, var->player.pos.y * ST + my, \
	var->player.pos.x * ST + mx);
	return ;
}

/**
 * DESCRIPTION:
 * Move player character.
 * PARAMETERS:
 * @param	int		x	Pixel modification of Y axis.
 * @param	int		y	Pixel modification of X axis.
 * @param	t_var	var	Data about game.
 */
void	move_pc(int x, int y, t_var *var)
{
	int	mx;
	int	my;

	mx = 0;
	my = 0;
	if (x == -1)
		mx = -100;
	else if (x == 1)
		mx = 100;
	else if (y == -1)
		my = -100;
	else if (y == 1)
		my = 100;
	update_win(mx, my, var);
	update_pos(x, y, var);
	printf("Moves: %d\n", var->player.nmoves);
	return ;
}
