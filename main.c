/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:06 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/14 15:40:22 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_from_conversion_table(int index, t_flags *modifiers)
{
	typedef void (*ptr_to_conversion_function)(t_flags *modifiers);
	ptr_to_conversion_function table[] =
	{
		decimal_conversion,
		decimal_conversion
		/*octal_conversion
		unsigned_integer_conversion
		hexadecimal_conversion_lowercase
		hexadecimal_conversion_uppercase
		float_conversion
		percentage_conversion*/
	};
	table[index](modifiers);
}

int type_conversion(t_flags *modifiers, char *format)
{
	char	available_conversions[9];
	int		index;

	index = 0;
	ft_strcpy(available_conversions, "di"); //ouxXf%

	while (available_conversions[index])
	{
		if (*format == available_conversions[index])
		{
			modifiers->conversion_index = index;
			print_from_conversion_table(index, modifiers);
			return (SUCCESS);
		}
	++index;
	}
	return (FAIL);
}

size_t	check_for_flags(char *format, t_flags *modifiers)
{
	char	*start;

	start = format;
	++format;

	format = check_sign_flag(modifiers, format);
	format = check_for_space_flag(modifiers, format);
	format = check_for_zero_flag(modifiers, format);
	format = check_decimal_flag(modifiers, format);
	format = check_minimum_field_of_width(modifiers,format);
	if (type_conversion(modifiers, format) == SUCCESS)
	{
		++format;
		return ((int)(format - start));
	}
	return (1);
}

void	ft_printf(char *format, ...)
{
	int		i;
	t_flags	*modifiers;

	i = 0;
	modifiers = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (!modifiers)
		exit(1);
	va_start(modifiers->va_pointer, format);
	while (format[i])
	{
		if (format[i] == '%')
			i += check_for_flags(&format[i], modifiers);
		write(1, &format[i], 1);
		++i;
	}
	ft_putchar('\n');
}

int	main(void)
{
	int	number;

	number = 11;
	ft_printf("MY this is a text %d ", number);




	//

	/*
	ft_putchar('\n');
	printf("\nOG this is a text %d\n", number);
	ft_putchar('\n');
	ft_printf("MY this is a text %d", number);
	ft_putchar('\n');
	printf("OG this is a text %d", number);
	ft_putchar('\n');
	ft_printf("MY this is a text %d", number);
	ft_putchar('\n');
	printf("OG this is a text %d", number);
	ft_putchar('\n');
	*/
	return (0);
}
