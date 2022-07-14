/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:13:38 by amateo-r          #+#    #+#             */
/*   Updated: 2021/09/07 13:13:44 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <malloc/malloc.h>

size_t	ft_strlen(const char *s);
int		ft_strffnotof(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_digits(int n);
int		ft_digits_base(unsigned long n, int base);
int		ft_putnbr_base(unsigned long n, char *base);
char	*ft_itoa(int n);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);
char	*ft_uitoa(unsigned int nb);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif
