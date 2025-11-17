/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:04:38 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/17 12:35:47 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TYPE "cspdiuxX%"
# define FLAG "-0# +"
# define HEX_BASE "0123456789abcdef"

# include <ctype.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_arg
{
	uint8_t		flags;
	size_t		width;
	size_t		precision;
	char		type;
	int			ret;
	const char	*format;
	va_list		args;
}				t_arg;

size_t	ft_printf(const char *format, ...);
void	get_format(t_arg *set);
void	get_flag(t_arg *set);
void	get_precision(t_arg *set);
void	get_width(t_arg *set);
void	get_type(t_arg *set);
void	putchr(t_arg *set);
void	putstr(t_arg *set);
size_t	max_s(size_t a, size_t b);
size_t	min_s(size_t a, size_t b);
void	print(const char c, t_arg *set);
void	print_memory(uintptr_t addr, t_arg *set);
size_t	memory_len(uintptr_t addr);
void	putaddr(t_arg *set);
void	putint(t_arg *set);

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar(const char c);
void	ft_putstr(const char *s, t_arg *set);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		calc_len(int n);


#endif