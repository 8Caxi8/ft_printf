/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:25:32 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/01 15:25:35 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(t_arg *set)
{
	if (*set->format == 'c')
		return (set->format++, putchr(set));
	if (*set->format == 's')
		return (set->format++, putstr(set));
	if (*set->format == 'p')
		return (set->format++, set->base = HEX_BASE_L, putaddr(set));
	if (*set->format == 'd' || *set->format == 'i')
		return (set->format++, set->base = DEC_BASE, putint(set));
	if (*set->format == 'u')
		return (set->format++, set->base = DEC_BASE, putuns(set));
	if (*set->format == 'x')
		return (set->format++, set->base = HEX_BASE_L, puthex(set));
	if (*set->format == 'X')
		return (set->format++, set->base = HEX_BASE_U, puthex(set));
	if (*set->format == '%')
		return (set->format++, print('%', set));
}

void	get_width_precision(t_arg *set)
{
	set->width = ft_atoi(set->format);
	set->precision = 0;
	if (set->width > 0)
		set->format += n_len(set->width, DEC_BASE);
	if (*set->format == '.')
	{
		set->format++;
		set->flags = set->flags | (1 << 5);
		set->precision = ft_atoi(set->format);
		while (ft_isdigit(*set->format))
			set->format++;
	}
}

void	get_flag(t_arg *set)
{
	set->flags = 0;
	while (ft_strchr(FLAG, *set->format))
	{
		if (*set->format == ' ')
			set->flags = set->flags | (1 << 0);
		if (*set->format == '+')
			set->flags = set->flags | (1 << 1);
		if (*set->format == '-')
			set->flags = set->flags | (1 << 2);
		if (*set->format == '0')
			set->flags = set->flags | (1 << 3);
		if (*set->format == '#')
			set->flags = set->flags | (1 << 4);
		set->format++;
	}
}

size_t	ft_printf(const char *format, ...)
{
	t_arg	set;

	va_start(set.args, format);
	set.format = format;
	set.ret = 0;
	while (*set.format)
	{
		if (*set.format == '%')
		{
			set.format++;
			get_flag(&set);
			get_width_precision(&set);
			get_type(&set);
			continue ;
		}
		else
			print(*set.format, &set);
		set.format++;
	}
	va_end(set.args);
	return (set.ret);
}
