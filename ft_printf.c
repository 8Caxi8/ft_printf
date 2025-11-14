/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:40:07 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/14 00:47:10 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_type(char type, t_arg *set)
{
	if (type == 'c')
		return (putchr(set));
	if (type == 's')
		return (putstr(set));
	if (type == 'p')
		return (putaddr(set));
	if (type == 'd' || type == 'i')
		return (putint(set));
	if (type == 'u')
		return (putuns(set));
	if (type == 'x' || type == 'X')
		return (puthex(set));
	if (type == '%')
		return (putperc(set));
}

size_t	get_width(char *format, t_arg *set)
{
	size_t	i;

	i = 0;
	if (ft_isdigit(format[i]))
		set->width = ft_atoi(format);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

size_t	get_precision(char *format, t_arg *set)
{
	size_t	i;

	i = 0;
	if (format[i] == '.')
	{
		set->flags = set->flags | (1 << 5);
		set->precision = ft_atoi(format + 1);
		while (ft_isdigit(format[++i]))
			;
	}
	return (i);
}

size_t	get_flag(char *format, t_arg *set)
{
	size_t	i;
	
	i = -1;
	while (ft_strchr(FLAG, format[++i]))
	{
		if (format[i] == ' ')
			set->flags = set->flags | (1 << 0);
		if (format[i] == '+')
			set->flags = set->flags | (1 << 1);
		if (format[i] == '-')
			set->flags = set->flags | (1 << 2);
		if (format[i] == '0')
			set->flags = set->flags | (1 << 3);
		if (format[i] == '#')
			set->flags = set->flags | (1 << 4);
	}
	return (i);
}

size_t	get_format(char *format, t_arg *set)
{
	size_t	i;

	i = 0;
	i += get_flag(format, set);
	i += get_width(format + i, set);
	i += get_precision(format + i, set);
	if (!ft_strchr(TYPE, format[i]))
		return (-1);
	i += get_type(format + i, set);
	return (i);
}

size_t	ft_printf(const char *format, ...)
{
	t_arg	set;
	int		i;

	va_start(set.args, format);
	set.flags = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i += get_format(format + i, &set);
		else
			ft_putchar(format[i++]);
	}
}
