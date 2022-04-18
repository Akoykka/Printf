/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:56:28 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 19:51:30 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch_table(t_flags *flags)
{
	static const t_dispatch_table	dispatch_table[12] = {
		charecter_conversion,
		string_conversion,
		pointer_conversion,
		decimal_conversion,
		decimal_conversion,
		unsigned_int_conversion,
		octal_conversion,
		hexadecimal_conversion,
		hexadecimal_conversion,
		float_conversion,
		percentage_conversion
	};

	dispatch_table[flags->conversion_type](flags);
}

char	*cpy_format(char *format, t_flags *flags)
{
	size_t		i;

	i = 0;
	while (format[i] != 'c' && format[i] != 's'
		&& format[i] != 'p' && format[i] != 'd' && format[i] != 'i'
		&& format[i] != 'o' && format[i] != 'u' && format[i] != 'x'
		&& format[i] != 'X' && format[i] != 'f' && format[i] != '%')
	{
		if (!format[i])
		{
			write(2, "error: undefined behavior", 25);
			free(flags);
			exit(1);
		}
		++i;
	}
	return (ft_strndup(format, &format[++i] - format));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_flags	*flags;
	va_list	list;
	int		return_value;

	i = 0;
	flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (!flags)
		exit(1);
	flags->printf_ret = 0;
	va_start((flags->va_ptr), format); //// miksi et toimiiiiii
	flags->va_ptr = &list;
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			i += get_flag_values(cpy_format((char *)&format[i], flags), flags);
			dispatch_table(flags);
		}	
		else
		{
			write(1, &format[i], 1);
			flags->printf_ret++;
			++i;
		}
	}
	return_value = flags->printf_ret;
	free(flags);
	return (return_value);
}
