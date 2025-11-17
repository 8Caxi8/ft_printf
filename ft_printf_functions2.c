#include "ft_printf.h"

void	putint(t_arg *set)
{
	return ;
	size_t	i;
	char	*n;

	n = ft_itoa(va_arg(set->args, int));
	i = -1;
	if (!(set->flags & (1 << 5)))
		set->precision = ft_strlen(ft_itoa(n, set->precision));
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
size_t	n_len(int nbr)
{
	size_t	i;
	long	n;

	n = nbr;
	i = -1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
}
