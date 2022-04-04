/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:05:55 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/22 10:21:33 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int number)
{
	int	lenght;

	lenght = 0;
	while (number != 0)
	{
		number = number / 10;
		++lenght;
	}
	return (lenght);
}

char	number_to_char(unsigned long long number)
{
	if (number >= 0 && number <= 9)
		return (number + '0');
	return (number + 87);
}		

char	*convert_number_to_base(unsigned long long number, int base)
{
	char	*conversion;

	if (number / base == 0)
	{
		conversion = ft_strnew(50);
		if (number < 0)
			conversion[0] = '-';
		conversion[ft_strlen(conversion)] = number_to_char(number);
		return (conversion);
	}
	else
	{
		conversion = convert_number_to_base(number / base, base);
		conversion[ft_strlen(conversion)] = number_to_char(number % base);
		return (conversion);
	}
}