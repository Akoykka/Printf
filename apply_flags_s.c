/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:39:51 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/16 10:15:34 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_apply_decimal_flag(t_flags *modifiers, char *pointer)
{
	if (modifiers->decimal_flag > (int)ft_strlen(pointer)
		|| modifiers->decimal_flag == 0)
		return (pointer);
	pointer = ft_strdup(pointer); // possible leak
	pointer[modifiers->decimal_flag] = '\0';
	return (pointer);
}

void	s_apply_and_print_minus_flag(t_flags *modifiers, char *pointer)
{	
	int	loop;

	loop = modifiers->minus_flag - (int)strlen(pointer);
	ft_putstr(pointer);
	while (loop-- > 0)
		ft_putchar(' ');
}

void	s_apply_and_print_width(t_flags *modifiers, char *pointer)
{
	int	loop;

	loop = modifiers->min_field_depth - (int)ft_strlen(pointer);
	while (loop-- > 0)
		ft_putchar(' ');
	ft_putstr(pointer);
}
