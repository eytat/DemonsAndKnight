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
void	exception_manager(int argc, char **argv);
void	throw_exception(char *message);

/**
 *	Método que comprueba si los parámetros pasados son los correctos.
 *	Comprueba:
 *	- Número de argumenos = 1.
 *	- Archivo con extensión = ".ber".
 *	- Existencia del archivo.
 *	- Tamaño mínimo de mapa.
 *	@param	int		argc	number of arguments of argv.
 *	@param	char	**argv	input of main.
 */
void	exception_manager(int argc, char **argv)
{
	int	len;
	int	fd;

	if (argc != 2)
		throw_exception("There must be only one .ber file;");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1] + len - 4, ".ber\0", 5) != 0)
		throw_exception("File must be filename.ber;");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		throw_exception("File doesn't exist;");
	}
	if (ch_map(fd, ft_columns(argv[1]), ft_rows(argv[1])) == 1)
	{
		close(fd);
		throw_exception("Incorrect map format");
	}
	close(fd);
	return ;
}

/**
 *	@param	int		col		Number of columns of filename.ber.
 *	@param	char	*line	Current read line of filename.ber
 */
int	ch_linelen(int col, char *line)
{
	int	r;

	r = 0;
	if ((int)ft_strlen(line) - 1 != col)
		r = 1;
	else if (line[0] != MWA || line[col - 1] != MWA)
		r = 1;
	return (r);
}

/**
 *	@param	int		r		Boolean flag and return value.
 *	@param	int		col		Number of columns of filename.ber.
 *	@param	char	*line	Current read line of filename.ber.
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
 *	- Tamaño mínimo de mapa.
 *	@param	int	fd	Filename.ber direction.
 *	@param	int	col	Number of columns of filename.ber.
 *	@param	int	row	Number of rows of filename.ber.
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
	if (cep[0] + cep[1] + cep[2] != 3)
		r = 1;
	line = get_next_line(fd);
	if (ft_strffnotof(line, MWA) == 1)
		r = 1;
	free(line);
	return (r);
}

/**
 *	Método que termina con el programa en caso de error.
 *	@param	char	*message	Custom error message displayed.
 */
void	throw_exception(char *message)
{
	printf("\nERROR: %s\n", message);
	exit(0);
	return ;
}
