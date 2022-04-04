/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/22 10:42:20 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_conversion(t_flags *modifiers)
{
	int		temp;
	char	*number;
	
	temp = va_arg(modifiers->va_pointer, unsigned long long);
	number = convert_number_to_base(temp, 10);
	o_apply_sign_flag(modifiers, &number);
	o_apply_decimal_flag(modifiers, &number);
	o_apply_space_flag(modifiers, &number);
	o_apply_min_field_width(modifiers, &number);
	ft_putstr(number);
}
/* OLD DECIMAL CONVERSION
void	decimal_conversion(t_flags *modifiers)
{
	int	*pointer;

	pointer = (int *)ft_memalloc(sizeof(int));
	*pointer = va_arg(modifiers->va_pointer, int);
	di_apply_plus_flag(modifiers, *pointer);
	di_apply_decimal_flag(modifiers, *pointer);
	di_apply_space_flag(modifiers, *pointer);
	di_apply_min_field_width(modifiers, *pointer);
	ft_putnbr(*pointer);
}
*/
void	string_conversion(t_flags *modifiers)
{
	char	*pointer;

	pointer = va_arg(modifiers->va_pointer, char *);
	pointer = s_apply_decimal_flag(modifiers, pointer);
	if (modifiers->minus_flag)
		s_apply_and_print_minus_flag(modifiers, pointer);
	else
		s_apply_and_print_width(modifiers, pointer);
}

void	octal_conversion(t_flags *modifiers)
{
	char	*number;
	int		temp;

	temp = va_arg(modifiers->va_pointer, unsigned int);
	number = convert_number_to_base(temp, OCTAL_BASE);
	o_apply_decimal_flag(modifiers, &number);
	o_apply_min_field_width(modifiers, &number);
	o_apply_zero_flag(modifiers, &number);
	o_apply_minus_flag(modifiers, &number);
	ft_putstr(number);
}

void	hexadecimal_conversion(t_flags *modifiers)
{
	char	*number;
	int		temp;

	temp = va_arg(modifiers->va_pointer, unsigned int);
	number = convert_number_to_base(temp, HEXADEC_BASE);
	o_apply_decimal_flag(modifiers, &number);
	o_apply_min_field_width(modifiers, &number);
	o_apply_zero_flag(modifiers, &number);
	o_apply_minus_flag(modifiers, &number);
	ft_putstr(number);
}

void	hexadecimal_conversion_uppercase(t_flags *modifiers)
{
	char	*number;
	int		temp;
	int		i;

	i = 0;
	temp = va_arg(modifiers->va_pointer, unsigned int);
	number = convert_number_to_base(temp, HEXADEC_BASE);
	o_apply_decimal_flag(modifiers, &number);
	o_apply_min_field_width(modifiers, &number);
	o_apply_zero_flag(modifiers, &number);
	o_apply_minus_flag(modifiers, &number);
	while (number[i])
	{
		ft_toupper(number[i]);
	}
	ft_putstr(number);
}

//if precision then no zero flag 

//	if minus flag no zero flag

// if plus no space flag