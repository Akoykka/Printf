/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:00:13 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/22 08:35:10 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_sign_flag(t_flags *modifiers, char *temp)
{
	if (*temp == '+')
	{
		modifiers->sign_flag = 1;
		return (++temp);
	}
	if (*temp == '-')
	{
		++temp;
		modifiers->minus_flag = ft_atoi(temp);
		temp = temp + int_len(modifiers->minus_flag);
	}
	return (temp);
}

char	*check_for_space_flag(t_flags *modifiers, char *temp)
{
	if (*temp == ' ')
	{
		++temp;
		modifiers->space_flag = ft_atoi(temp);
		temp = temp + int_len(modifiers->space_flag);
	}
	return (temp);
}

char	*check_for_zero_flag(t_flags *modifiers, char *temp)
{
	if (*temp == '0')
	{
		++temp;
		modifiers->zero_flag = ft_atoi(temp);
		temp = temp + int_len(modifiers->zero_flag);
	}
	return (temp);
}

char	*check_decimal_flag(t_flags *modifiers, char *temp)
{
	if (*temp == '.')
	{
		++temp;
		modifiers->decimal_flag = ft_atoi(temp);
		temp = temp + int_len(modifiers->decimal_flag);
	}
	return (temp);
}

char	*check_minimum_field_of_width(t_flags *modifiers, char *temp)
{
	if (*temp >= '1' && *temp <= '9')
	{
			modifiers->min_field_depth = ft_atoi(temp);
			temp = temp + int_len(modifiers->min_field_depth);
	}
	return (temp);
}

char	*check_for_length(t_flags *modifiers, char *format)
{
	if (*format == 'l')
	{
		format++;
		if (*format == 'l')
		{
			format++;
			modifiers->ll = 1;
		}
		else
		modifiers->l = 1;
	}
	if (*format == 'h')
	{
		format++;
		if (*format == 'h')
		{
			format++;
			modifiers->hh = 1;
		}
		else
			modifiers->h = 1;
	}
	return (format);
}
