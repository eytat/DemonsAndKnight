/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:05:24 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/28 19:45:19 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

/*
	S_PRINTDATA GUIDE

	va_list	args		List of format arguments %(cspdiuxX%)
	int		width;		String length
	int		pre			Precision number of some flags
	int		ret			Return value of printf
	int		pad;		Flag: "#"
	int		zero;		Flag: "0"
	int		minus;		Flag: "-"
	int		space;		Flag: " "
	int		sign;		Flag: "+"
	int		apost;		Flag: "'"
	int		point		Flag: "."
*/
typedef struct s_printdata
{
	va_list	args;
	int		width;
	int		pre;
	int		ret;
	int		pad;
	int		zero;
	int		minus;
	int		space;
	int		sign;
	int		apost;
	int		point;
}	t_printdata;

int			ft_printf(const char *fmt, ...);
int			ft_check(void *s);
int			ft_eval_flag(const char *fmt, int index, t_printdata *pd);
int			ch_format(char c);
int			ch_flag(t_printdata *pd);
int			fh_point(t_printdata *pd, const char *fmt, int index);
int			fh_zero(t_printdata *pd, const char *fmt, int index);
int			fh_minus(t_printdata *pd, const char *fmt, int index);
int			fh_space(t_printdata *pd, const char *fmt, int index);
void		ft_ws_zero(char *s, t_printdata *pd);
void		ft_ws_space(char *s, t_printdata *pd);
void		ft_ws_point(char *s, t_printdata *pd);
void		ft_write_c(t_printdata *pd);
void		ft_write_s(t_printdata *pd);
void		ft_write_p(t_printdata *pd);
void		ft_write_d(t_printdata *pd);
void		ft_write_u(t_printdata *pd);
void		ft_write_x(t_printdata *pd, int c);
void		ft_write_per(t_printdata *pd);

#endif
