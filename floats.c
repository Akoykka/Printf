/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:24:42 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/21 14:51:25 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*decimals_to_ascii(long double number)
{
	char	*decimals;
	int		loop;

	loop = 39;
	decimals = ft_strnew(41 + 1);
	ft_memset(decimals, '\0', 42);
	ft_memset(decimals, '.', 1);
	while (loop--)
	{
	number -= (long long)number;
	number *= 10;
	decimals[ft_strlen(decimals)] = (long long)number + '0';
	}
	return (decimals);
}

char	*float_to_ascii(t_flags *flags, long double number)
{
	char	*before_decimal;
	char	*decimals;
	char	*free_er;

	if (number < 0)
	{
		flags->negative = 1;
		number *= -1;
	}
	before_decimal = base_to_ascii((unsigned long long)number, DECIMAL_BASE);
	free_er = before_decimal;
	decimals = decimals_to_ascii(number);
	before_decimal = ft_strjoin(before_decimal, decimals);
	ft_strdel(&free_er);
	ft_strdel(&decimals);
	return (before_decimal);
}

char	*apply_precision_f(t_flags *flags, char *number)
{
	char	*target;
	int		precision;

	precision = 6;
	if (flags->precision)
		precision = flags->prec_val;
	target = (ft_strchr(number, '.') + precision);
	if (rounding_check(target, number) == ROUND_UP)
		rounding_operation(target, &number);
	if (flags->precision && !flags->prec_val && !flags->hash)
		*(ft_strchr(number, '.')) = '\0';
	else
		*(ft_strchr(number, '.') + precision + 1) = '\0';
	return (number);
}

void	handle_negative_zero(t_flags *flags, double temp)
{
	long long int	*double_to_int;
	char			sign;

	double_to_int = (long long int *)&temp;
	sign = (char)(*double_to_int >> 63);
	if (sign != 0)
		flags->negative = 1;
}

void	float_conversion(t_flags *flags)
{
	long double	temp;
	char		*number;

	temp = get_arg_f(flags);
	if (check_infinity_and_nan(temp, flags))
		return ;
	if (temp == 0)
		handle_negative_zero(flags, temp);
	number = float_to_ascii(flags, temp);
	number = apply_precision_f(flags, number);
	number = apply_plus_flag(flags, number);
	number = apply_space_flag(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}
