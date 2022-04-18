/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:24:42 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 09:54:18 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_round_nbr(char number)
{
	if (/*number == '0'||*/ number == '2' || number == '4'
		|| number == '6' || number == '8')
		return (1);
	return (0);
}

int	bankers_rounding(char *next_decimal, char *target)
{
	if (*next_decimal >= '6' && *next_decimal <= '9')
		return (ROUND_UP);
	if (*next_decimal == '4')
		return (bankers_rounding((next_decimal + 1), (target + 1)));
	if (*next_decimal == '5' && !is_round_nbr(*target))
		return (ROUND_UP);
	return (NO_ROUNDING);
}

int	rounding_check(char *target, char* number)
{
	char	*next_decimal;

	next_decimal = target + 1;
	//if (*next_decimal >= '6' && *next_decimal <= '9')
	//	return (ROUND_UP);
	if (*next_decimal == '5' && *target == '.' && (ft_atoi(number) % 2 == 0 || ft_atoi(number) == 0))
		return (NO_ROUNDING);
	if (bankers_rounding(next_decimal, target) == ROUND_UP)
		return (ROUND_UP);
	return (NO_ROUNDING);
}

void	replace_nb_with_rounded_nb(char **number, char *rounded_nb)
{
	char	*temp;
	char	*free_er;

	free_er = *number;
	temp = ft_strchr(*number, '.');
	ft_memmove(*number, &number[0][temp - *number], ft_strlen(&number[0][temp - *number]));
	*number = ft_strjoin(rounded_nb, *number);
	ft_strdel(&free_er);
	ft_strdel(&rounded_nb);
	return ;
}

void	rounding_operation(char *target, char **number)
{
	int		temp;
	char	*rounded_nb;
	char	*decimal_before_target;

	if (*target == '.')
	{
		temp = ft_atoi(*number);
		temp++;
		rounded_nb = ft_itoa(temp);
		replace_nb_with_rounded_nb(number, rounded_nb);
	}
	else
	{
		if (*target == '9')
		{
			decimal_before_target = &number[0][target - *number - 1];
			*target = '0';
			rounding_operation(decimal_before_target, number);
		}
		else
			++*target;
	}
}

char	*apply_precision_f(t_flags *flags, char *number)
{
	char	*temp;
	int		precision;

	precision = 6;
	if (flags->precision)
		precision = flags->prec_val;
	temp = (ft_strchr(number, '.') + precision);
	if (rounding_check(temp, number) == ROUND_UP)
		rounding_operation(temp, &number);
	if (flags->precision && !flags->prec_val && !flags->hash)
		*(ft_strchr(number, '.')) = '\0';
	else
		*(ft_strchr(number, '.') + precision + 1) = '\0';
	return (number);
}
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

/*0.4445

0.4446

0.4443

0.9443

0.04445

0.06666

0.4447

precision 1
0.94444
0.94446
0.999999999

99.999999999



Jos 6

pointer 6 kohdalle

katsotaan 7 jos tarvii pyoristaa.

jos on yli 5 palautetaan round_up ja pointteriin lisataan yksi, jos
pointer on jo 9 niin lisataan aikaisempaan numeroon 1
lisataan kunnes loytyy joku mika ei ole 9

jos piste niin sitten atoi ja +1
ja takas asciiksi ja memmove

*/

