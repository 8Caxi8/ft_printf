/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:40:07 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/17 12:35:40 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

void	get_type(t_arg *set)
{
	if (*set->format == 'c')
		return (set->format++, putchr(set));
	if (*set->format == 's')
		return (set->format++, putstr(set));
	if (*set->format == 'p')
		return (set->format++, putaddr(set));
	if (*set->format == 'd' || *set->format == 'i')
		return (set->format++, putint(set));
	/*if (*type == 'u')
		return (putuns(set));
	if (*type == 'x' || *type == 'X')
		return (puthex(set));
	if (*type == '%')
		return (putperc(set)); */
}

void	get_width(t_arg *set)
{
	set->width = ft_atoi(set->format);
	if (set->width > 0)
		set->format += ft_strlen(ft_itoa(set->width));
}

void	get_precision(t_arg *set)
{
	set->precision = 0;
	if (*set->format == '.')
	{
		*set->format++;
		set->flags = set->flags | (1 << 5);
		set->precision = ft_atoi(set->format);
		while (ft_isdigit(*set->format))
			set->format++;
	}
}

void	get_flag(t_arg *set)
{
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

void	get_format(t_arg *set)
{
	set->format++;
	get_flag(set);
	get_width(set);
	get_precision(set);
	printf("<<%i>>", set->flags);
	printf("<<%lu>>", set->width);
	printf("<<%lu>>", set->precision);
	printf("<<%c>>", *set->format);
	get_type(set);
}

size_t	ft_printf(const char *format, ...)
{
	t_arg	set;
	size_t	i;

	va_start(set.args, format);
	set.format = format;
	set.flags = 0;
	set.ret = 0;
	while (*set.format)
	{
		if (*set.format == '%')
		{
			get_format(&set);
			continue ;
		}
		else
			print(*set.format, &set);
		*set.format++;
	}
	va_end(set.args);
	return (set.ret);
}
