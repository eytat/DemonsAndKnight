/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:25:26 by amateo-r          #+#    #+#             */
/*   Updated: 2021/11/13 11:15:42 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libsl.h"

int	main(int argc, char **argv)
{
	t_var	var;

	if (!exception_manager(argc, argv))
	{
		init_window(argv[1], &var);
		get_map(argv[1], &var);
		build_map(&var);
		mlx_hook(var.mlx_win, 17, 1L << 17, close_win, &var);
		mlx_key_hook(var.mlx_win, key_manager, &var);
		mlx_loop(var.mlx);
	}
	return (0);
}
