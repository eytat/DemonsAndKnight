/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:00:32 by amateo-r          #+#    #+#             */
/*   Updated: 2021/12/10 16:21:10 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libsl.h"

int		close_win(t_var *var);
void	select_keycase(int x, int y, t_var *var);
int		key_manager(int key, t_var *var);

/**
 * Close the game when ESC key is holded.
 * Keycodes:
 * 	ESC keycode: 53
 * @param	t_var	*var	Data about game.
 */
int	close_win(t_var *var)
{
	printf("Closing...");
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit(0);
	return (0);
}

/**
 * Determinates the event when one of the keys WASD are holded.
 * @param	int		x		Modification of X Axis.
 * @param	int		y		Modification of Y Axis.
 * @param	t_var	*var	Data about game.
 */
void	select_keycase(int x, int y, t_var *var)
{
	if (var->map.board[var->player.pos.x + x] \
	[var->player.pos.y + y] == MSP)
		move_pc(x, y, var);
	else if (var->map.board[var->player.pos.x + x] \
	[var->player.pos.y + y] == MEN)
	{
		move_pc(x, y, var);
		var->nenemies--;
	}
	else if (var->map.board[var->player.pos.x + x] \
	[var->player.pos.y + y] == MEX)
	{
		if (var->nenemies == 0)
		{
			printf("Moves: %d\n", var->player.nmoves + 1);
			exit(0);
		}
	}
	return ;
}

/**
 * Keycodes:
 * 	W = 13.
 * 	A = 0.
 * 	S = 1.
 * 	D = 2.
 * @param	int		key		Codekey of keyboard input.
 * @param	t_var	*var	Data about game.
 */
int	key_manager(int key, t_var *var)
{
	if (key == 13)
		select_keycase(-1, 0, var);
	else if (key == 0)
		select_keycase(0, -1, var);
	else if (key == 1)
		select_keycase(1, 0, var);
	else if (key == 2)
		select_keycase(0, 1, var);
	else if (key == 53 || key == 65307)
		close_win(var);
	return (0);
}
