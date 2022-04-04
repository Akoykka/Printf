/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:20:08 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/04 19:23:46 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_arg_di(va_list *va_pointer, char *format)
{
	if (ft_strstr(format, "hh"))
		return (va_arg(*va_pointer, int));
	if (ft_strchr(format, 'h'))
		return (va_arg(*va_pointer, int));
	if (ft_strstr(format, "ll"))
		return (va_arg(*va_pointer, signed long long));
	if (ft_strchr(format, 'l'))
		return (va_arg(*va_pointer, signed long));
	return (va_arg(*va_pointer, signed int));
}

unsigned long long	get_arg_oux(va_list *va_pointer, char *format)
{
	if (ft_strstr(format, "hh"))
		return (va_arg(*va_pointer, unsigned int));
	if (ft_strstr(format, "h"))
		return (va_arg(*va_pointer, unsigned int));
	if (ft_strstr(format, "ll"))
		return (va_arg(*va_pointer, unsigned long long));
	if (ft_strstr(format, "l"))
		return (va_arg(*va_pointer, unsigned long));
	return (va_arg(*va_pointer, unsigned int));
}

long double	get_arg_f(va_list *va_pointer, char *format)
{
	if (ft_strstr(format, "l"))
		return (va_arg(*va_pointer, double));
	if (ft_strstr(format, "L"))
		return (va_arg(*va_pointer, long double));
	return (va_arg(*va_pointer, float));
}
