
#include "libft/libft.h"
#include <stdio.h>

char number_to_hex(unsigned long long number)
{
	if (number >= 0 && number <= 9)
		return (number + '0');
	else //(number >= 10 && number <= 16)
		return (number + 87);
}		

char	*hex_conversion(unsigned long long number)
{
	char	*conversion;
	char	hex_number;

	if (number / 16 == 0)
	{
		conversion = ft_strnew(50);
		conversion[ft_strlen(conversion)] = number_to_hex(number);
		return (conversion);
	}
	else
	{
		conversion = hex_conversion(number / 16);
		conversion[ft_strlen(conversion)] = number_to_hex(number % 16);
		return (conversion);
	}
}

char	number_to_octal(unsigned long long number)
{
	return (number + '0');
}		

char	*octal_conversion(unsigned long long number)
{
	char	*conversion;
	char	octal_number;

	if (number / 8 == 0)
	{
		conversion = ft_strnew(50);
		conversion[ft_strlen(conversion)] = number_to_octal(number);
		return (conversion);
	}
	else
	{
		conversion = octal_conversion(number / 8);
		conversion[ft_strlen(conversion)] = number_to_octal(number % 8);
		return (conversion);
	}
}

char	number_to_char(unsigned long long number)
{
	if (number >= 0 && number <= 9)
		return (number + '0');
	return (number + 87);
}		

char	*convert_number_to_base(unsigned long long number, int base)
{
	char	*conversion;

	if (number / base == 0)
	{
		conversion = ft_strnew(50);
		conversion[ft_strlen(conversion)] = number_to_char(number);
		return (conversion);
	}
	else
	{
		conversion = convert_number_to_base(number / base, base);
		conversion[ft_strlen(conversion)] = number_to_char(number % base);
		return (conversion);
	}
}

// compile : gcc hextesti.c -I . -I libft -L libft -lft -g

// VAIN KAHDEKSAN NUMERON TARKKUUDELLA MIKALI EI OLE ERITELTY LONGIA
int main(void)
{
	char	*str;
	char	*str2;
	
	str = convert_number_to_base(-654, 16);
/*	str = octal_conversion(654);
	str2 = hex_conversion(99999999999999);
	printf("octalconv of 654 is:%s correct 1216\n", str);
	str = octal_conversion(777);
	printf("octalconv of 777 is:%s correct 1411\n", str);
	str = octal_conversion(0);
	printf("octalconv of 0 is:%s correct 0\n", str);
	printf("99999999999999 is\n%s\ncorrect is \n5af3107a3fff\n", str2);
	*/
	str = convert_number_to_base(654, 8);
	printf("Convert to base \n octal (654)\n %s \n (correct 1216)\n", str);
	str = convert_number_to_base(15446744073709551613, 16);
	printf("MY hexa base		(-654) %s\n", str);
	str = convert_number_to_base(654, 16);
	printf("MY hexa base		(654) %s\n", str);
	printf("OG hexadecimal of	(-654):%llx\n", 15446744073709551613);
	printf("OG hexadecimal of	(654) :%x\n", 654);
	return (0);
}