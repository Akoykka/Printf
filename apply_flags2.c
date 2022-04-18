/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:35:36 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 19:51:26 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(t_flags *flags, char *number)
{
	if (flags->precision)
	{
		if (!flags->prec_val && is_value_zero(number))
			return (ft_memset(number, '\0', ft_strlen(number)));
		if (flags->prec_val > (int)ft_strlen(number))
		{
		flags->prec_val -= (int)ft_strlen(number);
		number = pad_with_zeroes(number, flags->prec_val, flags);
		}
	}
	return (number);
}

char	*s_apply_precision(t_flags *flags, char *string)
{
	char	*free_er;

	free_er = string;
	if (flags->precision && flags->prec_val < (int)ft_strlen(string))
	{
		string = ft_strndup(string, flags->prec_val);
		check_alloc(string, free_er, flags);
		ft_strdel(&free_er);
	}
	return (string);
}
