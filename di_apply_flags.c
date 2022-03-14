/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:15:58 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/14 23:14:00 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	di_apply_decimal_flag(t_flags *modifiers, int number)
{
	int	loop;

	loop = modifiers->decimal_flag - int_len(number);
	while (loop-- > 0)
		ft_putchar('0');
}

void	di_apply_space_flag(t_flags *modifiers, int number)
{
	int	loop;

	loop = modifiers->space_flag - (int_len(number));

	while (loop-- > 0)
		ft_putchar(' ');

}

void	di_apply_zero_flag(t_flags *modifiers, int number)
{
	int	loop;

	loop = modifiers->zero_flag - (int_len(number));

	while (loop-- > 0)
		ft_putchar('0');

}

void apply_min_field_width(t_flags *modifiers, int number)
{
	int	loop;

	loop = modifiers->min_field_depth - (int_len(number));

	while (loop-- > 0)
		ft_putchar(' ');
}

void apply_plus_flag(t_flags *modifiers, int number)
{
	t_flags *ptr;

	ptr = modifiers;
	if (number >= 0 && modifiers->sign_flag == 1)
		ft_putchar('+');
}