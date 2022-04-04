/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/04 19:23:37 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_conversion(va_list *va_pointer, char *format)
{
	long long			temp;
	char				*number;

	temp = get_arg_di(va_pointer, format);
	number = longlong_to_ascii(temp, DECIMAL_BASE);
	number = check_plus_flag(format, number);
	// VANHA PAIKKA CHECK PLUS FLAG TESTAA !
	//number = check_space_flag(format, number);
	number = apply_precision(format, number);
	print_result(format, number);
}
void	unsigned_int_conversion(va_list *va_pointer, char *format)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(va_pointer, format);
	number = base_to_ascii(temp, DECIMAL_BASE);
	number = check_hash_flag(format, number);
	number = check_plus_flag(format, number);
	number = check_space_flag(format, number);
	number = apply_precision(format, number);
	print_result(format, number);
}

void	string_conversion(va_list *va_pointer, char *format)
{
	char				*string;

	string = va_arg(*va_pointer, char *);
	string = s_apply_precision(format, string);
	print_result(format, string);
}

void	octal_conversion(va_list *va_pointer, char *format)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(va_pointer, format);
	number = base_to_ascii(temp, OCTAL_BASE);
	number = check_hash_flag(format, number);
	//number = check_plus_flag(format, number);
	number = check_space_flag(format, number);
	number = apply_precision(format, number);
	print_result(format, number);
}

void	hexadecimal_conversion(va_list *va_pointer, char *format)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(va_pointer, format);
	number = base_to_ascii(temp, HEXADECIMAL_BASE);
	number = check_hash_flag(format, number);
	//number = check_plus_flag(format, number);
	number = check_space_flag(format, number);
	number = apply_precision(format, number);
	print_result(format, number);
}

void	hexadecimal_conversion_uppercase(va_list *va_pointer, char *format)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(va_pointer, format);
	number = base_to_ascii(temp, HEXADECIMAL_BASE);
	number = check_hash_flag(format, number);
	//number = check_plus_flag(format, number);
	number = check_space_flag(format, number);
	number = apply_precision(format, number);
	toupper_everything(number);
	print_result(format, number);
}

void	charecter_conversion(va_list *va_pointer, char *format)
{
	char				temp;

	temp = (char)va_arg(*va_pointer, unsigned int);
	print_result(format, &temp);
}

void	pointer_conversion(va_list *va_pointer, char *format)
{
	void				*temp;
	char				*number = NULL;
	char				*prefix;
	char				*free_er;

	free_er = number;
	temp = va_arg(*va_pointer, void *);
	number = base_to_ascii((unsigned long long)temp, HEXADECIMAL_BASE);
	prefix = ft_strnew(2);
	ft_strcpy(prefix, "0x");
	number = ft_strjoin(prefix, number);
	//ft_strdel(&free_er);
	//ft_strdel(&temp);
	print_result(format, number);
}
void	percentage_conversion(va_list *va_pointer, char *format)
{
	char	*percentage;

	(void)va_pointer;
	percentage = ft_strnew(1);
	ft_memset(percentage, '%', 1);
	print_result(format, percentage);
}

void	float_conversion(va_list *va_pointer, char *format)
{
	long double	temp;
	char		*number;

	temp = get_arg_f(va_pointer, format);
	number = float_to_ascii(temp);
	number = check_plus_flag(format, number);
	number = apply_precision_f(format, number);
	print_result(format, number);
}

// Muuta arvo





/*
muuta arvo hexadecimaaliksi niin se nayttaa osoittteen.
if precision then no zero flag 

//	if minus flag no zero flag

// if plus no space flag

# works with 
s
First + or - or # 0 flag must be after that

width must be before preciesion

precision comes last.



first apply precision 

then apply + or space

calculate width and apply - 0 or none flag
*/