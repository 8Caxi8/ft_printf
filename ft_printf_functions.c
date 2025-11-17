/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:32:31 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/17 12:32:43 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

void	print(const char c, t_arg *set)
{
	ft_putchar(c);
	set->ret++;
}

void	putchr(t_arg *set)
{
	size_t	i;
	
	i = 0;
	if (set->flags & (1 << 2))
	{
		print((char) va_arg(set->args, int), set);
		while (++i < set->width)
			print(' ', set);
	}
	else
	{
		while (++i < set->width)
			print(' ', set);
		print((char) va_arg(set->args, int), set);
	}
}

void	putstr(t_arg *set)
{
	size_t	i;
	char	*s;

	s = va_arg(set->args, char*);
	i = -1;
	if (!(set->flags & (1 << 5)))
		set->precision = ft_strlen(s);
	if (set->flags & (1 << 2))
	{
		while (s[++i] && i < set->precision)
			print(s[i], set);
		while (i++ < set->width)
			print(' ', set);
	}
	else
	{
		while (set->width > ft_strlen(s) && ++i < set->width - min_s(set->precision, ft_strlen(s)))
			print(' ', set);
		i = -1;
		while (s[++i] && i < min_s(set->precision, ft_strlen(s)))
			print(s[i], set);
	}
}

void	putaddr(t_arg *set)
{
	uintptr_t ptr;
	size_t	i;

	ptr = (uintptr_t) va_arg(set->args, void*);
	if (!ptr)
		return (ft_putstr("0x0", set));
	i = memory_len(ptr) + 2;
	if (set->flags & (1 << 2))
	{
		ft_putstr("0x", set);
		print_memory(ptr, set);
		while (++i <= set->width)
			print(' ', set);
	}
	else
	{
		while (++i <= set->width)
			print(' ', set);
		ft_putstr("0x", set);
		print_memory(ptr, set);
	}
}

size_t memory_len(uintptr_t addr)
{
	if (addr >= 16)
		return (memory_len(addr / 16) + 1);
	return (1);
}

void	print_memory(uintptr_t addr, t_arg *set)
{
	if (addr >= 16)
		print_memory(addr / 16, set);
	print(HEX_BASE[addr % 16], set);
}

size_t	max_s(size_t a, size_t b)
{
	return (a * (a > b) + b * (a <= b));
}

size_t	min_s(size_t a, size_t b)
{
	return (a * (a < b) + b * (a >= b));
}
