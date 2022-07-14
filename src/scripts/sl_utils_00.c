/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:39:55 by amateo-r          #+#    #+#             */
/*   Updated: 2021/11/08 16:39:56 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libsl.h"

/**
 * DESCRIPTION:
 * Display characters map of param 'map'.
 * PARAMETERS:
 * @param	t_map	*map	Data of filename.map.
 */
void	print_map(char *fn, t_map *map)
{
	int	x;
	int	y;
	int	row;
	int	col;

	row = ft_rows(fn);
	col = ft_columns(fn);
	x = -1;
	while (++x < row)
	{
		y = -1;
		while (++y < col)
			printf("%c", map->board[x][y]);
		printf ("\n");
	}
	return ;
}

/**
 * DESCRIPTION:
 * Counts each character of a line until find '\n'.
 * RETURN:
 * Returns number of columns.
 * PARAMETERS:
 * @param	char	*fn	File path.
 */
size_t	ft_columns(char *fn)
{
	int		fd;
	size_t	col;
	char	c;

	fd = open(fn, O_RDONLY);
	col = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		col++;
	close(fd);
	return (col);
}

/**
 * DESCRIPTION:
 * Counts the '\n' of each line until the end's file .
 * RETURN:
 * Returns number of rows.
 * PARAMETERS:
 * @param	char	*fn	File path.
 */
size_t	ft_rows(char *fn)
{
	int		fd;
	char	c;
	size_t	row;

	fd = open(fn, O_RDONLY);
	row = 0;
	while (read(fd, &c, 1) != 0)
		if (c == '\n')
			row++;
	close(fd);
	return (row);
}

/**
 * DESCRIPTION:
 * Method that prints an error meassage when it happens.
 * RETURN:
 * Always return 1.
 * PARAMETERS:
 * @param	char	*message	Custom error message displayed.
 */
int	throw_exception(char *message)
{
	ft_printf("\nERROR: %s\n", message);
	return (1);
}
