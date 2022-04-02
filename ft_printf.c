/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:56:28 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/02 17:59:32 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_type_table(int index, va_list *va_pointer, char *format)
{
	typedef void (*conversion_type_table)(va_list *va_pointer, char *format);
	conversion_type_table table[] =
	{
		charecter_conversion,
		string_conversion,
		pointer_conversion,
		decimal_conversion,
		decimal_conversion,
		octal_conversion,
		unsigned_int_conversion,
		hexadecimal_conversion,
		hexadecimal_conversion_uppercase,
		//float_conversion,
		percentage_conversion
	};
	table[index](va_pointer, format);
}

void	print_next_parameter(char *format, va_list *va_pointer)
{
	char	available_conversions[12];
	int		i;

	i = 0;
	ft_strcpy(available_conversions, "cspdiouxX%");
	while (available_conversions[i])
	{
		if (ft_strchr(format, available_conversions[i]) != NULL)
			conversion_type_table(i, va_pointer, format);
		++i;
	}
}

char	*cpy_format(char *format)
{
	size_t		i;

	i = 0;
	while (format[i] && format[i] != 'c' && format[i] != 's'
		&& format[i] != 'p' && format[i] != 'd' && format[i] != 'i'
		&& format[i] != 'o' && format[i] != 'u' && format[i] != 'x'
		&& format[i] != 'X' && format[i] != 'f' && format[i] != '%')
	{
		++i;
	}
	return (ft_strndup(format, &format[++i] - format));
}

int	ft_printf(char *format, ...)
{
	int		i;
	va_list	va_pointer;
	char	*format_cpy;

	i = 0;
	va_start(va_pointer, format);
	while (format[i])
	{
		if (format[i] == '%')
		{	
			++i;
			format_cpy = cpy_format(&format[i]);
			i += (int)ft_strlen(format_cpy);
			print_next_parameter(format_cpy, &va_pointer);
		}
		else
		{
			write(1, &format[i], 1);
			++i;
		}
	}
	return (11);
}
