/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_idu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:25:45 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/01 15:25:46 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putint(t_arg *set)
{
	size_t	len;
	long	n;
	t_sign	s;

	n = (long) va_arg(set->args, int);
	s.sign = get_sign(&n, &s, set);
	len = n_len(n, set->base);
	if ((set->flags & (1 << 5)) && set->precision == 0 && n == 0)
		len = 0;
	if (set->precision < len)
		set->precision = len;
	set->width = max_s(max_s(set->precision, len), set->width);
	if (set->flags & (1 << 2))
		left_align(set, len, &s, n);
	else
		right_align(set, len, &s, n);
}

void	left_align(t_arg *set, size_t len, t_sign *s, uintmax_t n)
{
	size_t	i;

	i = -1;
	if (s->sign == 1)
	{
		print (s->signc, set);
		i++;
	}
	while (++i < (set->precision - len) + s->sign * 1)
		print('0', set);
	ft_putnbr_base_print(n, set->base, set);
	i += len;
	while (++i <= set->width)
		print(' ', set);
}

void	right_align(t_arg *set, size_t len, t_sign *s, uintmax_t n)
{
	size_t	i;

	i = -1;
	if (!(set->flags & (1 << 5)) && (set->flags & (1 << 3)))
	{
		if (s->sign == 1)
			(print (s->signc, set), i++);
		while (++i < set->width - len)
			print('0', set);
	}
	else
	{
		if (s->sign == 1)
			i++;
		while (++i < set->width - (max_s(set->precision, len)))
			print(' ', set);
		if (s->sign == 1)
			print (s->signc, set);
	}
	i = -1;
	while (++i < set->precision - len)
		print('0', set);
	ft_putnbr_base_print(n, set->base, set);
}

void	putuns(t_arg *set)
{
	unsigned long	n;
	t_sign			s;
	size_t			len;

	n = va_arg(set->args, unsigned int);
	s.sign = 0;
	len = n_len(n, set->base);
	if ((set->flags & (1 << 5)) && (set->precision + n == 0))
		len = 0;
	if (set->precision < len)
		set->precision = len;
	set->width = max_s(max_s(set->precision, len), set->width);
	if (set->flags & (1 << 2))
		left_align(set, len, &s, n);
	else
		right_align(set, len, &s, n);
}
