/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:06 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/22 11:18:36 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void flags_table(int index, t_flags *modifiers, char **number)
{
	typedef void (*flags_table)(t_flags *modifiers char **number);
	flags_table table[] =
	{
		o_apply_sign_flag,
		o_apply_zero_flag,
		o_apply_decimal_flag,
		o_apply_minus_flag,
		o_apply_space_flag,
		o_apply_min_field_width,
		o_apply_min_field_width,
		o_apply_min_field_width,
		o_apply_min_field_width,
		o_apply_min_field_width,
		o_apply_min_field_width,
		o_apply_min_field_width,
		o_apply_min_field_width,
		o_apply_min_field_width
	};
	table[index](modifiers, **number);
}
int apply_flags(char *format, char **number, int flag_value)
{
	char	flag_type[16];
	int		index;

	index = 0;
	ft_memset(flag_types, '\0', 16)
	ft_strcpy(flag_type, "-+0. 123456789"); //ouxXf%
	while (available_conversions[index])
	{
		if (*format == flag_type[index])
		{

			flags_table(index, number, flag_value);
			return (SUCCESS);
		}
	++index;
	}
	return (FAIL);
}


void conversion_type_table(int index, t_flags *modifiers)
{
	typedef void (*conversion_type_table)(t_flags *modifiers);
	conversion_type_table table[] =
	{
		decimal_conversion,
		decimal_conversion,
		string_conversion,
		octal_conversion,
		hexadecimal_conversion,
		/*hexadecimal_conversion_uppercase
		 float_conversion
		percentage_conversion 
		*/

	};
	table[index](modifiers);
}

int type_conversion(t_flags *modifiers, char *format)
{
	char	available_conversions[9];
	int		index;

	index = 0;
	ft_strcpy(available_conversions, "disox"); //ouxXf%
	while (available_conversions[index])
	{
		if (*format == available_conversions[index])
		{
			modifiers->conversion_index = index;
			conversion_type_table(index, modifiers);
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
	format = check_minimum_field_of_width(modifiers, format);
	format = check_for_space_flag(modifiers, format);
	format = check_for_zero_flag(modifiers, format);
	format = check_decimal_flag(modifiers, format);
	format = check_for_length(modifiers, format);
	if (type_conversion(modifiers, format) == SUCCESS)
	{
		++format;
		return ((int)(format - start));
	}
	return (1);
}

void	reset_flags(t_flags *modifiers)
{
	ft_memset(modifiers->type, '\0', 10);
	modifiers->minus_flag = 0;
	modifiers->sign_flag = 0;
	modifiers->zero_flag = 0;
	modifiers->decimal_flag = 0;
	modifiers->space_flag = 0;
	modifiers->conversion_index = 0;
	modifiers->min_field_depth = 0;
	modifiers->ll = 0;
	modifiers->l = 0;
	modifiers->h = 0;
	modifiers->hh = 0;
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
	char str[] = "kullikikkeli";


	number2 = 12;
	number = 111;


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

	//combinations on strings
	ft_printf("MY 10.5: |%10.5s|", str);
	printf("OG 10.5: |%10.5s|\n", str);
	
	//ft_printf("regular: |%s|", str);
	ft_printf("MY.5: |%.5s|", str);
	ft_printf("MY25: |%25s|", str);
	ft_printf("MY5: |%5s|", str);
	
	printf("OG5: |%5s|\n", str);
	printf("OG25: |%25s|\n", str);
	printf("OG.5: |%.5s|\n", str);
	ft_printf("MY -5.5: |%-5.5s|", str);
	printf("OG -5.5: |%-5.5s|\n", str);

	
	
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
	
	printf("\nOG5: 111 number min_width 5o\n");
	printf("OG5: |%5o|\n", number);
	ft_printf("MY5: |%5o|", number);

	printf("\nOG5: 111 number min_width 25o\n");
	printf("OG25: |%25o|\n", number);
	ft_printf("MY25: |%25o|", number);

	printf("\nOG5: 111 number precision .5o\n");
	printf("OG.5: |%.5o|\n", number);
	ft_printf("MY.5: |%.5o|", number);

	printf("\nOG5: 111 number -5 with .5o\n");
	printf("OG -5.5: |%-5.5o|\n", number);
	ft_printf("MY -5.5: |%-5.5o|\n", number);

	printf("\nOG5: 111 number  -5o\n");
	printf("OG -5: |%-5o|\n", number);
	ft_printf("MY -5: |%-5o|\n", number);
	
	printf("\nhexadecimals \n");
	printf("OG25: |%025x|\n", number);
	ft_printf("MY25: |%025x|", number);

	printf("OG25: |%-10x|\n", number2);
	ft_printf("MY25: |%-10x|", number2);

	printf("OG25: |%.25x|\n", number);
	ft_printf("MY25: |%.25x|", number);

	printf("OG25: |%025x|\n", number2);
	ft_printf("MY25: |%025x|", number2);





	return (0);
}
