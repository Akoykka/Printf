/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/16 19:17:23 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	//free(&pointer);
}

void	string_conversion(t_flags *modifiers)
{
	char	*pointer;

	pointer = ft_strnew(999);
	pointer = va_arg(modifiers->va_pointer, char *);
	pointer = s_apply_decimal_flag(modifiers, pointer);
	if (modifiers->minus_flag)
		s_apply_and_print_minus_flag(modifiers, pointer);
	else
		s_apply_and_print_width(modifiers, pointer);
	//free(&pointer);
}

void	octal_conversion(t_flags *modifiers)
{
	char	*pointer;
	unsigned long long number;

	number = va_arg(modifiers->va_pointer, unsigned long long);
	pointer = convert_number_to_base(number, 8); //muista freeaa tan funktion allokoima muisti
	pointer = o_apply_minus_flag(modifiers, pointer);
	pointer = o_apply_decimal_flag(modifiers, pointer);
	pointer = o_apply_min_field_width_flag(modifiers, pointer);
	pointer = o_apply_zero_flag(modifiers, pointer);
	ft_putstr([pointer]);
}
//if precision then no zero flag 

//	if minus flag no zero flag

// if plus no space flag