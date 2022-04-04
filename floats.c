/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:24:42 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/04 19:23:38 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*decimals_to_ascii(long double number)
{
	char	*decimals;

	decimals = ft_strnew(41 + 1);
	ft_memset(decimals, '\0', 42);
	if (number < 0)
	{
		number *= -1;
		decimals[0] = '-';
	}
	loop = 40;
	while (loop--)
	{
	number -= (long long)number;
	number *= 10;
	decimals[ft_strlen(decimals)] = (long long)number + '0';
	}
	return (decimals);
}
char	*float_to_ascii(long double number)
{	
	char	*first_part;
	char	*second_part;
	char	*free_er;

	first_part = longlong_to_ascii((long long)number, DECIMAL_BASE);
	second_part = decimals_to_ascii(number);
	first_part = ft_strjoin(first_part, second_part);
	//ft_strdel(&free_er);
	//ft_strdel(second_part);
	return(first_part);
}


int	is_round_nbr(char number)
{
	if (number == '0' && number == '2' && number == '4'
		&& number == '6' && number == '8')
		return (1);
	return (0);
}

int	bankers_rounding(char *number)
{	
	if (number == '5')
		return (ROUND_UP);
	return (NO_ROUNDING);
}
int rounding_check(char *number)
{
	char	*next_decimal;

	next_decimal = number + 1;
	if (next_decimal >= '0' && next_decimal <= '4')
		return (NO_ROUNDING);
	if (next_decimal >= '6' && next_decimal <= '9')
		return (ROUND_UP);
	if (is_round_nbr(number) && bankers_rounding(next_decimal) == ROUND_UP)
		return (ROUND_UP);
	return (NO_ROUNDING);
}

void rounding_operation(char *target, char *number)
{






	
}

char	*apply_precision_f(char *format, char *number)
{
	char	*temp;
	int		precision;

	precision = 7;
	temp = ft_strchr(format, '.');
	if (temp)
	{
		if (ft_isdigit(*(temp + 1)))
			precision = ft_atoi(temp + 1);
		else
			precision = 1;
	}
	temp = (ft_strchr(number, '.') + precision);
	if (rounding_check(temp) == ROUND_UP)
	{
		rounding_operation(temp, number);
	}
	*(temp + 1) = '\0';
	return (number);
}

0.4445

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



