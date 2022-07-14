/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:46 by amateo-r          #+#    #+#             */
/*   Updated: 2021/11/25 14:37:37 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This file handler input fails and end the program
**	with a error message.
**	- Empty files.
**	- Incorrect file extension.
**	- Incorrect map format.
*/

#include "../../include/libsl.h"

int		ch_linelen(int col, char *line);
int		ch_chars(int r, int col, char *line, int cep[3]);
int		ch_map(int fd, int col, int row);
int		ch_resolution(int col, int row);
int		exception_manager(int argc, char **argv);

/**
 * DESCRIPTION:
 * Checks possible fails. Checks if there is an inut, correct 
 * .ber extension file, file permissions, map size and correct 
 * map elements.
 * RETURN:
 * If something goes wrong return 1 else 0.
 * @param	int		argc	number of arguments of argv.
 * @param	char	**argv	input of main.
 */
int	exception_manager(int argc, char **argv)
{
	int	len;
	int	fd;
	int	fail;

	fail = 0;
	if (argc != 2)
		fail = throw_exception("There must be only one .ber file;");
	len = ft_strlen(argv[1]);
	if (!fail && (len < 5 || ft_strncmp(argv[1] + len - 4, ".ber\0", 5) != 0))
		fail = throw_exception("File must be filename.ber;");
	fd = open(argv[1], O_RDONLY);
	if (!fail && fd < 0)
		fail = throw_exception("File isn't accesible;");
	else if (!fail && ch_resolution(ft_columns(argv[1]), ft_rows(argv[1])))
		fail = throw_exception("Incorrect map size;");
	else if (!fail && ch_map(fd, ft_columns(argv[1]), ft_rows(argv[1])) == 1)
		fail = throw_exception("Incorrect map format;");
	close(fd);
	if (fail)
		exit(0);
	return (fail);
}

/**
 * DESCRIPTION:
 * Checks that the length of the line is equal to col.
 * RETURN:
 * If there is difference number of columns between lines
 * return 1 else 0.
 * @param	int		col		Number of columns of filename.ber.
 * @param	char	*line	Current read line of filename.ber
 */
int	ch_linelen(int col, char *line)
{
	int	r;
	int	len;

	r = 0;
	len = ft_strlen(line) - 1;
	if (len != col)
		r = 1;
	else if (line[0] != MWA || line[col - 1] != MWA)
		r = 1;
	return (r);
}

/**
 * DESCRIPTION:
 * Checks that there are the minimun number or elements in
 * the map.
 * RETURN:
 * If some element miss return 1, else 0.
 * 
 * @param	int		r		Boolean flag and return value.
 * @param	int		col		Number of columns of filename.ber.
 * @param	char	*line	Current read line of filename.ber.
 */
int	ch_chars(int r, int col, char *line, int cep[3])
{
	int	i;

	i = 0;
	while (r == 0 && ++i < col - 1)
	{
		if (line[i] == MEN)
			cep[0] = 1;
		else if (line[i] == MEX)
			cep[1] = 1;
		else if (line[i] == MST)
			cep[2] = 1;
		else if (line[i] != MWA && line[i] != MSP)
			r = 1;
	}
	return (r);
}

/**
 * DESCRIPTION:
 * Checks that the size and elements of the map.ber file.
 * All rows and columns must have the same length and 
 * correct character data elements.
 * RETURN:
 * If some check fail return 1 else 0.
 * @param	int	fd	Filename.ber direction.
 * @param	int	col	Number of columns of filename.ber.
 * @param	int	row	Number of rows of filename.ber.
 */
int	ch_map(int fd, int col, int row)
{
	int		r;
	int		cep[3];
	char	*line;

	r = 0;
	line = get_next_line(fd);
	if (ft_strffnotof(line, MWA) == 1)
		r = 1;
	free(line);
	while (--row > 1 && r == 0)
	{
		line = get_next_line(fd);
		r = ch_linelen(col, line);
		r = ch_chars(r, col, line, cep);
		free(line);
	}
	if (!r && (cep[0] + cep[1] + cep[2] != 3))
		r = 1;
	line = get_next_line(fd);
	if (!r && ft_strffnotof(line, MWA) == 1)
		r = 1;
	free(line);
	return (r);
}

/**
 * DESCRIPTION:
 * Checks that the number of cells aren't bigger than the 
 * established limite. Is for rows and columns. Pretends 
 * prevent that game's window be bigger than the pc's 
 * resolution.
 * RETURN:
 * If map size is bigger than max resolution return 1
 * else 0.
 * @param	int	col	Number of columns of filename.ber.
 * @param	int	row	Number of rows of filename.ber.

 */
int	ch_resolution(int col, int row)
{
	int	r;

	r = 0;
	if (col > WINRES_WIDTH || row > WINRES_HEIGHT)
		r = 1;
	else if (col == 0 || row == 0)
		r = 1;
	return (r);
}
