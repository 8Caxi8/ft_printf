/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_idu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:10:47 by caxi              #+#    #+#             */
/*   Updated: 2025/11/20 13:10:48 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putint(t_arg *set)
{
	size_t	len;
	long	n;
	t_sign	sign;

	n = (long) va_arg(set->args, int);
	sign.sign = get_sign(&n, &sign, set);
	len = n_len(n, set->base);
	if ((set->flags & (1 << 5)) && (set->precision + n == 0))
		len = 0;
	if (set->precision < len)
		set->precision = len;
	set->width = max_s(max_s(set->precision, len), set->width);
	if (set->flags & (1 << 2))
		left_align(set, len, &sign, n);
	else
		right_align(set, len, &sign, n);
}

void	left_align(t_arg *set, size_t len, t_sign *sign, uintmax_t n)
{
	size_t	i;

	i = -1;
	if (sign->sign == 1)
	{
		print (sign->signc, set);
		i++;
	}
	while (++i < (set->precision - len) + sign->sign * 1)
		print('0', set);
	ft_putnbr_base_print(n, set->base, set);
	i += len;
	while (++i <= set->width)
		print(' ', set);
}

void	right_align(t_arg *set, size_t len, t_sign *sign, uintmax_t n)
{
	size_t	i;

	i = -1;
	if (!(set->flags & (1 << 5)) && (set->flags & (1 << 3)))
	{
		if (sign->sign == 1)
			(print (sign->signc, set), i++);
		while (++i < set->width - len)
			print('0', set);
	}
	else
	{
		if (sign->sign == 1)
			i++;
		while (++i < set->width - (max_s(set->precision, len)))
			print(' ', set);
		if (sign->sign == 1)
			print (sign->signc, set);
	}
	i = -1;
	while (++i < set->precision - len)
		print('0', set);
	ft_putnbr_base_print(n, set->base, set);
}

void	putuns(t_arg *set)
{
	unsigned long	n;
	t_sign			sign;
	size_t			len;

	n = va_arg(set->args, unsigned int);
	sign.sign = 0;
	len = n_len(n, set->base);
	if ((set->flags & (1 << 5)) && (set->precision + n == 0))
		len = 0;
	if (set->precision < len)
		set->precision = len;
	set->width = max_s(max_s(set->precision, len), set->width);
	if (set->flags & (1 << 2))
		left_align(set, len, &sign, n);
	else
		right_align(set, len, &sign, n);
}
