/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:11:40 by caxi              #+#    #+#             */
/*   Updated: 2025/11/20 13:11:41 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putaddr(t_arg *set)
{
	uintptr_t	ptr;
	size_t		i;

	ptr = (uintptr_t) va_arg(set->args, void *);
	if (!ptr)
		return (printstr("(nil)", set));
	i = n_len(ptr, HEX_BASE_L) + 2;
	if (set->flags & (1 << 2))
	{
		ft_putstr("0x", set);
		ft_putnbr_base_print(ptr, HEX_BASE_L, set);
		while (++i <= set->width)
			print(' ', set);
	}
	else
	{
		while (++i <= set->width)
			print(' ', set);
		ft_putstr("0x", set);
		ft_putnbr_base_print(ptr, HEX_BASE_L, set);
	}
}

void	putstr(t_arg *set)
{
	char	*s;

	s = va_arg(set->args, char *);
	if (!s)
	{
		if (set->flags & (1 << 5) && set->precision < 6)
			return ;
		s = "(null)";
	}
	printstr(s, set);
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

void	printstr(char *s, t_arg *set)
{
	size_t	i;

	i = -1;
	if (!(set->flags & (1 << 5)))
		set->precision = ft_strlen(s);
	set->width = max_s(min_s(set->precision, ft_strlen(s)), set->width);
	if (set->flags & (1 << 2))
	{
		while (s[++i] && i < set->precision)
			print(s[i], set);
		while (i++ < set->width)
			print(' ', set);
	}
	else
	{
		while (++i < set->width - min_s(set->precision, ft_strlen(s)))
			print(' ', set);
		i = -1;
		while (s[++i] && i < min_s(set->precision, ft_strlen(s)))
			print(s[i], set);
	}
}
