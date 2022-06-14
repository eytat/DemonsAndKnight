/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:59:33 by amateo-r          #+#    #+#             */
/*   Updated: 2021/11/08 14:59:37 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSL_H
# define LIBSL_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define IMG_WIDTH 64
# define IMG_HEIGHT 64
# define ST 100

# define MSP '0'
# define MWA '1'
# define MEN 'C'
# define MEX 'E'
# define MST 'P'

# define SP_PATH "./src/img/bg_tile.xpm"
# define W_PATH "./src/img/wall_tile.xpm"
# define E_PATH "./src/img/daemon.xpm"
# define EX_PATH "./src/img/exit_tile.xpm"
# define P_PATH "./src/img/knight.xpm"

/**
 * @param	int	x	Coordenada para eje X.
 * @param	int y	Coordenada para eje Y.
 */
typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

/**
 * @param	int		row		Number of rows of board.
 * @param	int		col		Number of columns of board.
 * @param	char	**board	Matrix with data map of "filename.ber".
 */
typedef struct s_map
{
	int		row;
	int		col;
	char	**board;
}	t_map;

/**
 * @param	void	*img		Información gráfica en píxeles.
 * @param	char	*addr		Dirección de memoria.
 * @param	int		bpp			Bits per pixel.
 * @param	int		line_length	Diferencia de longitud con la ventanta.
 * @param 	int		endian		Dirección de orden de (small endian 4b).
*/
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

/**
 * @param	t_image		c_img	Image file of charater.
 * @param	t_vector2	pos		Current character position on map.
 * @param	int			nmoves	Number of moves do it by player.
 */
typedef struct s_character
{
	t_image		c_img;
	t_vector2	pos;
	int			nmoves;
}	t_character;

/**
 * @param	void		*mlx		Conexión con la miniLibx.
 * @param	void		mlx_win		Contenedor de la ventana X11.
 * @param	t_map		map			Structure with all data world of "filename.ber".
 * @param	t_image		wall		Image data of wall tiles.
 * @param	t_image		space		Image data of empty tiles.
 * @param	t_image		door		Image data of exit tiles.
 * @param	t_character	enemy		Data about enemies on map.
 * @param	t_character	player		Data about player character.
 * @param	int			nenemies	Number of enemies to beat to win.
*/
typedef struct s_var
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_image		wall;
	t_image		space;
	t_image		door;
	t_character	enemy;
	t_character	player;
	int			nenemies;
}	t_var;

size_t	ft_columns(char *fn);
size_t	ft_rows(char *fn);
void	exception_manager(int argc, char **argv);
void	init_window(char *fn, t_var *var);
void	get_map(char *fn, t_var *var);
void	build_map(t_var *var);
void	move_pc(int x, int y, t_var *var);
int		close_win(t_var *var);
int		key_manager(int key, t_var *var);

// Utils not relevant that will be deleted
void	print_map(char *fn, t_map *map);

#endif
