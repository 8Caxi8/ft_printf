/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:10:29 by caxi              #+#    #+#             */
/*   Updated: 2025/11/20 13:10:30 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthex(t_arg *set)
{
	unsigned int	n;
	size_t			len;

	n = va_arg(set->args, unsigned int);
	len = n_len(n, set->base);
	if ((set->flags & (1 << 5)) && (set->precision + n == 0))
		len = 0;
	if (set->precision < len)
		set->precision = len;
	set->width = max_s(max_s(set->precision, len), set->width);
	if (set->flags & (1 << 2))
		hex_left_align(set, len, n);
	else
		hex_right_align(set, len, n);
}

size_t	starterhex(t_arg *set)
{
	print('0', set);
	print((set->base)[15] + 18, set);
	return (2);
}

void	hex_left_align(t_arg *set, size_t len, uintmax_t n)
{
	size_t	i;
	size_t	pref;

	i = -1;
	pref = 0;
	if (set->flags & (1 << 4))
		pref = 2;
	if (set->flags & (1 << 4) && n != 0)
		starterhex(set);
	while (++i < (set->precision - len))
		print('0', set);
	ft_putnbr_base_print(n, set->base, set);
	i += len + pref;
	while (++i <= set->width)
		print(' ', set);
}

void	hex_right_align(t_arg *set, size_t len, uintmax_t n)
{
	size_t	i;

	i = -1;
	if (!(set->flags & (1 << 5)) && (set->flags & (1 << 3)))
	{
		if (set->flags & (1 << 4) && n != 0)
			i += starterhex(set);
		while (++i < set->width - len)
			print('0', set);
	}
	else
	{
		if (set->flags & (1 << 4) && n != 0)
			i += 2;
		while (++i < set->width - (max_s(set->precision, len)))
			print(' ', set);
		if (set->flags & (1 << 4) && n != 0)
			starterhex(set);
	}
	i = -1;
	while (set->precision > 0 && ++i < set->precision - len)
		print('0', set);
	ft_putnbr_base_print(n, set->base, set);
}
