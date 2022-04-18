/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:05:55 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 18:12:36 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	number_to_char(unsigned long long number)
{
	if (number >= 0 && number <= 9)
		return (number + '0');
	return (number + 87);
}		

char	*base_to_ascii(unsigned long long number, int base)
{
	char	*conversion;

	if (number / base == 0)
	{
		conversion = ft_strnew(50);
		if (!conversion)
			return (NULL);
		conversion[ft_strlen(conversion)] = number_to_char(number);
		return (conversion);
	}
	else
	{
		conversion = base_to_ascii(number / base, base);
		conversion[ft_strlen(conversion)] = number_to_char(number % base);
		return (conversion);
	}
}

void	toupper_everything(char *number)
{
	while (*number)
	{
		*number = ft_toupper(*number);
		++number;
	}
}

void	check_alloc(char *allocated, char *free_er, t_flags *free_er2)
{
	if (allocated)
		return ;
	free(&free_er);
	free(&free_er2);
	write(2, "Malloc Error(printf)...Exiting\n", 32);
	exit (1);
}

int	is_number_just_space(char *number)
{
	while (*number)
	{
		if (*number != ' ')
			return (0);
		++number;
	}
	return (1);
}
