/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:06 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/15 19:10:40 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_from_conversion_table(int index, t_flags *modifiers)
{
	typedef void (*ptr_to_conversion_function)(t_flags *modifiers);
	ptr_to_conversion_function table[] =
	{
		decimal_conversion,
		decimal_conversion,
		string_conversion
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
	ft_strcpy(available_conversions, "dis"); //ouxXf%

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
	format = check_minimum_field_of_width(modifiers, format);
	if (type_conversion(modifiers, format) == SUCCESS)
	{
		++format;
		return ((int)(format - start));
	}
	return (1);
}

void reset_flags(t_flags *modifiers)
{
	modifiers->minus_flag = 0;
	modifiers->sign_flag = 0;
	modifiers->zero_flag = 0;
	modifiers->decimal_flag = 0;
	modifiers->space_flag = 0;
	modifiers->conversion_index = 0;
	modifiers->min_field_depth = 0;
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
		{
			i += check_for_flags(&format[i], modifiers);
			reset_flags(modifiers);
			if (!format[i])
				break ;
		}
		else
		{
			write(1, &format[i], 1);
			++i;
		}
	}
	ft_putchar('\n'); // just for convenience
}

int	main(void)
{
	int	number;
	int number2;
	char str[] = "ananasakaama";


	number2 = 12;
	number = 11;
	/*
	ft_printf("MY just integer %d", number);
	printf("OG just integer %d\n", number);
	ft_printf("MY integer with - and .10 %-.10d", number);
	printf("OG integer with - and .10 %-.10d\n", number);
	ft_printf("MY integer with + and .10 %+.10d", number);
	printf("OG integer with + and .10 %+.10d\n", number);

	ft_printf("first number:%d second number:%d", number, number2);
	printf("first number:%d second number:%d\n", number, number2);

	ft_printf("first number w flags :%0.9d second number w/o:%d", number, number2);
	printf("first number w flags :%.9d second number w/o:%d\n", number, number2);
	ft_printf("MY alternatin numbers %d%d%d%d%d%d%d%d%d", number, number2,number, number2, number, number2,number, number2,number);
	printf("OGalternatin numbers %d%d%d%d%d%d%d%d%d\n", number, number2,number, number2, number, number2,number, number2,number);
	*/
	ft_printf("regular: |%s|", str);
	ft_printf(".5: |%.5s|", str);
	ft_printf("5: |%5s|", str);
	ft_printf("25: |%25s|", str);

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
