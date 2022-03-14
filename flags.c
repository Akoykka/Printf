/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:00:13 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/14 15:12:03 by akoykka          ###   ########.fr       */
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
	if (*(temp + 1) == '-')
	{
		modifiers->sign_flag = -1;
		return (++temp);
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
	if (ft_isdigit(*temp))
	{
			modifiers->min_field_depth = ft_atoi(temp);
			temp = temp + int_len(modifiers->min_field_depth);
	}
	return (temp);
}
