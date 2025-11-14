/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:04:38 by dansimoe          #+#    #+#             */
/*   Updated: 2025/11/14 00:13:09 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TYPE "cspdiuxX%"
# define FLAG "-0# +"

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

typedef struct	s_arg
{
	uint8_t	flags;
	size_t	width;
	size_t	precision;
	char	type;
	va_list	args;
}				t_arg;


#endif