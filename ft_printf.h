/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:04:38 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/01 15:37:15 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TYPE "cspdiuxX%"
# define FLAG "-0# +"
# define HEX_BASE_L "0123456789abcdef"
# define HEX_BASE_U "0123456789ABCDEF"
# define DEC_BASE "0123456789"

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_arg
{
	uint8_t		flags;
	size_t		width;
	size_t		precision;
	char		type;
	char		*base;
	int			ret;
	const char	*format;
	va_list		args;
}				t_arg;

typedef struct s_sign
{
	int			sign;
	char		signc;
}				t_sign;

size_t	ft_printf(const char *format, ...);
void	get_flag(t_arg *set);
void	get_width_precision(t_arg *set);
void	get_type(t_arg *set);
void	putchr(t_arg *set);
size_t	max_s(size_t a, size_t b);
size_t	min_s(size_t a, size_t b);
void	print(const char c, t_arg *set);
void	putaddr(t_arg *set);
void	putint(t_arg *set);
size_t	n_len(uintmax_t nbr, char *base);
void	ft_putnbr_base_print(uintmax_t n, char *base, t_arg *set);
int		get_sign(intmax_t *n, t_sign *s, t_arg *set);
void	putuns(t_arg *set);
void	puthex(t_arg *set);
void	putstr(t_arg *set);
void	ft_putstr(const char *s, t_arg *set);
size_t	starterhex(t_arg *set);
void	printstr(char *s, t_arg *set);
void	left_align(t_arg *set, size_t len, t_sign *sign, uintmax_t n);
void	right_align(t_arg *set, size_t len, t_sign *sign, uintmax_t n);
void	hex_left_align(t_arg *set, size_t len, uintmax_t n);
void	hex_right_align(t_arg *set, size_t len, uintmax_t n);

#endif