/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:56:28 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/10 00:04:47 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch_table(t_flags *flags)
{
	if (flags->conversion_type == 0 && charecter_conversion(flags))
		return ;
	if (flags->conversion_type == 1 && string_conversion(flags))
		return ;
	if (flags->conversion_type == 2 && pointer_conversion(flags))
		return ;
	if (flags->conversion_type == 3 && decimal_conversion(flags))
		return ;
	if (flags->conversion_type == 4 && decimal_conversion(flags))
		return ;
	if (flags->conversion_type == 5 && octal_conversion(flags))
		return ;
	if (flags->conversion_type == 6 && unsigned_int_conversion(flags))
		return ;
	if (flags->conversion_type == 7 && hexadecimal_conversion(flags))
		return ;
	if (flags->conversion_type == 8 && hexadecimal_conversion_uppercase(flags))
		return ;
	if (flags->conversion_type == 9 && float_conversion(flags))
		return ;
	if (flags->conversion_type == 10 && percentage_conversion(flags))
		return ;
}

char	*cpy_format(char *format)
{
	size_t		i;

	i = 0;
	while (format[i] && format[i] != 'c' && format[i] != 's'
		&& format[i] != 'p' && format[i] != 'd' && format[i] != 'i'
		&& format[i] != 'o' && format[i] != 'u' && format[i] != 'x'
		&& format[i] != 'X' && format[i] != 'f' && format[i] != '%')
		++i;
	return (ft_strndup(format, &format[++i] - format));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_flags	*flags;

	i = 0;
	flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	flags->printf_ret = 0;
	va_start(*flags->va_ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{	
			++i;
			i += get_flag_values(cpy_format((char *)&format[i]), flags);
			dispatch_table(flags);
		}	
		else
		{
			write(1, &format[i], 1);
			flags->printf_ret++;
			++i;
		}
	}
	return (flags->printf_ret);
}
