/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 19:07:28 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char	*handle_min_long_long(t_flags *flags)
{
	char	*number;

	flags->negative = 1;
	number = ft_strdup("-9223372036854775807");
	check_alloc(number, NULL, flags);
	return (number);
}
*/
void	decimal_conversion(t_flags *flags)
{
	long long			temp;
	char				*number;

	number = NULL;
	temp = get_arg_di(flags);
	if (temp < 0)
	{
		temp *= -1;
		flags->negative = 1;
	}
	number = base_to_ascii((unsigned long long)temp, DECIMAL_BASE);
	check_alloc(number, NULL, flags);
	number = apply_precision(flags, number);
	number = apply_space_flag(flags, number);
	number = apply_plus_flag(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	unsigned_int_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, DECIMAL_BASE);
	check_alloc(number, NULL, flags);
	number = apply_hash_flag(flags, number);
	number = apply_precision(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	octal_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, OCTAL_BASE);
	check_alloc(number, NULL, flags);
	number = apply_precision(flags, number);
	number = apply_hash_flag_oct(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	hexadecimal_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, HEXADECIMAL_BASE);
	check_alloc(number, NULL, flags);
	number = apply_precision(flags, number);
	number = apply_hash_flag(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	if (flags->conversion_type == HEX_UPPER)
		toupper_everything(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	percentage_conversion(t_flags *flags)
{
	char	*percentage;

	percentage = ft_strnew(1);
	check_alloc(percentage, NULL, flags);
	ft_memset(percentage, '%', 1);
	if (flags->width > (int)ft_strlen(percentage))
		percentage = pad_width(flags, percentage);
	flags->printf_ret += ft_strlen(percentage);
	ft_putstr(percentage);
	ft_strdel(&percentage);
}
