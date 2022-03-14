/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/14 23:39:21 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_conversion(t_flags *modifiers)
{
	int	*pointer;

	pointer = ft_memalloc(sizeof(int));
	*pointer = va_arg(modifiers->va_pointer, int);
	apply_plus_flag(modifiers, *pointer);
	di_apply_decimal_flag(modifiers, *pointer);
	di_apply_space_flag(modifiers, *pointer);
	apply_min_field_width(modifiers, *pointer);
	ft_putnbr(*pointer);
	free(&pointer);
}

//void	string_conversion(t_flags *modifiers)
