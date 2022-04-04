/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:06 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/04 19:23:50 by akoykka          ###   ########.fr       */
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
		float_conversion,
		percentage_conversion
	};
	table[index](va_pointer, format);
}

void	print_next_parameter(char *format, va_list *va_pointer)
{
	char	available_conversions[12];
	int		i;

	i = 0;
	ft_strcpy(available_conversions, "cspdiouxXf%");
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
	ft_putchar('\n');
	return (691337);
}

int	main(void)
{
	int		number;
	int		number2;
	char	str[] = "TESTSTRING";
	number2 = 12;
	number = 111;
	
	int	i = 1;
	int	j = 12;
	int	k = 123;
	int	l = 1234;
	int	m = 12345;
	int	n = 123456;

	int zero = 0;
	int negative = -1;

	char charry = 120;
	short int shorty = 3333;;
	long int 	longy = -212312333;
	long long int longylongy = 696969696969;

	ft_printf("MY|%+010ld|\n", longy);

	printf("\n Zero with + sign\n\n");
	printf("%+d\n", zero);

	printf("\n Negative number first with then without + sign\n\n");
	printf("%+d\n", negative);
	printf("%d\n", negative);


	printf("\nPrecision (.10)\n\n");
	printf("OG|%.10d|\n", i);
	ft_printf("MY|%.10d|\n", i);
	printf("OG|%.10d|\n", j);
	ft_printf("MY|%.10d|\n", j);
	printf("OG|%.10d|\n", k);
	ft_printf("MY|%.10d|\n", k);
	printf("OG|%.10d|\n", l);
	ft_printf("MY|%.10d|\n", l);
	printf("OG|%.10d|\n", m);
	ft_printf("MY|%.10d|\n", m);
	printf("OG|%.10d|\n", n);
	ft_printf("MY|%.10d|\n", n);

	printf("\n\nZeros (010)\n\n");
	printf("OG|%010d|\n", i);
	ft_printf("MY|%010d|\n", i);
	printf("OG|%010d|\n", j);
	ft_printf("MY|%010d|\n", j);
	printf("OG|%010d|\n", k);
	ft_printf("MY|%010d|\n", k);
	printf("OG|%010d|\n", l);
	ft_printf("MY|%010d|\n", l);
	printf("OG|%010d|\n", m);
	ft_printf("MY|%010d|\n", m);

	printf("\n\n+ and Zeros (10)\n\n");
	printf("OG|%+010d|\n", i);
	ft_printf("MY|%+010d|\n", i);
	printf("OG|%+010d|\n", j);
	ft_printf("MY|%+010d|\n", j);
	printf("OG|%+010d|\n", k);
	ft_printf("MY|%+010d|\n", k);
	printf("OG|%+010d|\n", l);
	ft_printf("MY|%+010d|\n", l);
	printf("OG|%+010d|\n", m);
	ft_printf("MY|%+010d|\n", m);

	printf("\n\n (10)\n\n");
	printf("OG|%10d|\n", i);
	ft_printf("MY|%10d|\n", i);
	printf("OG|%10d|\n", j);
	ft_printf("MY|%10d|\n", j);
	printf("OG|%10d|\n", k);
	ft_printf("MY|%10d|\n", k);
	printf("OG|%10d|\n", l);
	ft_printf("MY|%10d|\n", l);


	printf("\n\n (10 SHUFFLLE)\n\n");

	ft_printf("MY|%+10d|", i);
	printf("OG|%+10d|\n", i);

	printf("OG|%-10d|\n", j);
	ft_printf("MY|%-10d|", j);

	printf("OG|% 10d|\n", k);
	ft_printf("MY|% 10d|", k);

	printf("OG|%10.6d|\n", l);
	ft_printf("MY|%10.6d|", l);


	ft_printf("first number:%d second number:%d", number, number2);
	printf("first number:%d second number:%d\n", number, number2);
	ft_printf("MY alternatin numbers %d%d%d%d%d%d%d%d%d", number, number2,number, number2, number, number2,number, number2,number);
	printf("OGalternatin numbers %d%d%d%d%d%d%d%d%d\n", number, number2,number, number2, number, number2,number, number2,number);
	printf("\nOG5: 111 number min_width 25o\n");
	printf("OG25: |%25o|\n", number);
	ft_printf("MY25: |%25o|", number);

	//ft_printf("MY just integer %d", number);
	printf("OG just integer %d\n", number);
	ft_printf("MY integer with - and .10 %-.10d", number);
	printf("OG integer with - and .10 %-.10d\n", number);
	ft_printf("MY integer with + and .10 %+.10d", number);
	printf("OG integer with + and .10 %+.10d\n", number);

	ft_printf("first number w flags :%0.9d second number w/o:%d", number, number2);
	printf("first number w flags :%.9d second number w/o:%d\n", number, number2);

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

	printf("\n\n short + and Zeros (10)\n\n");
	printf("OG|%+010hd|\n", shorty);
	ft_printf("MY|%+010hd|\n", shorty);

	printf("\n\n unsigned char + and Zeros (10)\n\n");
	printf("OG|%+010hhd|\n", charry);
	ft_printf("MY|%+010hhd|\n", charry);

	printf("\n\n long + and Zeros (10)\n\n");
	printf("OG|%+010ld|\n", longy);
	ft_printf("MY|%+010ld|\n", longy);

	printf("\n\n long long + and Zeros (10)\n\n");
	printf("OG|%+010lld|\n", longylongy);
	ft_printf("MY|%+010lld|\n", longylongy);

	//printf("OG|%+010lld|\n", m);
	//ft_printf("MY|%+010lld|\n", m);

	return (0);
}
