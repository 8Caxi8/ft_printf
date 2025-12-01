/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:11:16 by caxi              #+#    #+#             */
/*   Updated: 2025/12/01 15:17:22 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_sign(intmax_t *n, t_sign *s, t_arg *set)
{
	if (*n < 0 || (set->flags & (1 << 1)) || (set->flags & (1 << 0)))
	{
		if (*n < 0)
		{
			*n *= -1;
			s->signc = '-';
		}
		else if (set->flags & (1 << 1))
			s->signc = '+';
		else if (set->flags & (1 << 0))
			s->signc = ' ';
		return (1);
	}
	return (0);
}

size_t	n_len(uintmax_t nbr, char *base)
{
	size_t	i;
	size_t	b_l;

	b_l = ft_strlen(base);
	if (b_l < 2)
		return (0);
	i = 1;
	while (nbr >= b_l)
	{
		nbr /= b_l;
		i++;
	}
	return (i);
}

void	ft_putnbr_base_print(uintmax_t n, char *base, t_arg *set)
{
	size_t	b_l;

	b_l = ft_strlen(base);
	if (b_l < 2)
		return ;
	if ((set->flags & (1 << 5)) && (set->precision == 0) && (n == 0))
		return ;
	if (n >= b_l)
		ft_putnbr_base_print(n / b_l, base, set);
	print(base[n % b_l], set);
}
