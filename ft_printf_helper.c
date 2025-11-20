/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:32:31 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/20 13:11:05 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(const char c, t_arg *set)
{
	ft_putchar(c);
	set->ret++;
}

size_t	max_s(size_t a, size_t b)
{
	return (a * (a > b) + b * (a <= b));
}

size_t	min_s(size_t a, size_t b)
{
	return (a * (a < b) + b * (a >= b));
}

void	ft_putstr(const char *s, t_arg *set)
{
	if (!s)
		return ;
	while (*s)
		print(*s++, set);
}
