/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:04:37 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/02 15:38:29 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*align_to_the_right(char *number, int width)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(width);
	ft_memset(temp, ' ', width);
	number = ft_strjoin(temp, number);
	//ft_strdel(&temp);
	//ft_strdel(&free_er);
	return (number);
}

char	*pad_with_zeroes(char *number, int width)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(width);
	ft_memset(temp, '0', width);
	if (*number == '-')
	{
		*number = '0';
		temp[0] = '-';
	}
	if (*number == '+')
	{
		*number = '0';
		temp[0] = '+';
	}
	number = ft_strjoin(temp, number);
	//ft_strdel(&temp);
	//ft_strdel(&free_er);
	return (number);
}

int	first_digit_is_zero(char *format)
{
	while (*format && *format != '.' && !ft_isdigit(*format))
		++format;
	if (*format == '0')
		return (1);
	return (0);
}

char	*align_to_the_left(char *number, int width)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(width);
	ft_memset(temp, ' ', width);
	number = ft_strjoin(number, temp);
	//ft_strdel(&temp);
	//ft_strdel(&free_er);
	return (number);
}

char	*pad_width(char *format, char *number, int width)
{
	width -= ft_strlen(number);
	if (ft_strchr(format, '-'))
		number = align_to_the_left(number, width);
	else
	{
		if (first_digit_is_zero(format))
			number = pad_with_zeroes(number, width);
		else
			number = align_to_the_right(number, width);
	}
	return (number);
}
