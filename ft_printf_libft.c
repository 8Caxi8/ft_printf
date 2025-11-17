/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:41:18 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/17 12:07:30 by dansimoe         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (_ISdigit);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = -1;
	ptr = s;
	while (++i < n)
		ptr[i] = 0;
}

void	ft_putstr(const char *s, t_arg *set)
{
	if (!s)
		return ;
	while (*s)
		print(*s++, set);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	buffer = malloc(size * nmemb);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number *= 10;
		number += nptr[i] - '0';
		i++;
	}
	return (sign * number);
}

int	calc_len(int n)
{
	long	nbr;
	int		i;

	nbr = n;
	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	if (nbr < 10)
		return (i);
	else
		return (i + calc_len(nbr / 10));
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		len;
	int		i;

	len = calc_len(n);
	nbr = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (n < 0)
		nbr *= -1;
	while (i < len)
	{
		str[len - 1 - i] = (nbr % 10) + '0';
		i++;
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
