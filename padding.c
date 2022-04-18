/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:04:37 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/16 21:18:13 by akoykka          ###   ########.fr       */
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
	ft_strdel(&temp);
	ft_strdel(&free_er);
	return (number);
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


char	*pad_with_zeroes(char *number, int width)
{
	char	*temp;
	char	*free_er;
	char	*temp2;

	free_er = number;
	temp = ft_strnew(width);
	ft_memset(temp, '0', width);
	if (*number == '-')
	{
		*number = '0';
		*temp = '-';
	}
	if (*number == '+')
	{
		*number = '0';
		*temp = '+';
	}
	if (*number == ' ') // floatteja varten
	{
		*number = '0';
		*temp = ' ';
	}
	temp2 = ft_strchr(number, 'x');
	if (temp2 != NULL)
	{
		*temp2 = '0';
		temp[1] = 'x';
	}
	if (ft_strlen(number) == 0)
		ft_memset(temp, ' ', width);
	number = ft_strjoin(temp, number);
	ft_strdel(&temp);
	ft_strdel(&free_er);
	return (number);
}

char	*align_to_the_left(char *number, int width)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(width);
	ft_memset(temp, ' ', width);
	number = ft_strjoin(number, temp);
	ft_strdel(&temp);
	ft_strdel(&free_er);
	return (number);
}

char	*pad_width(t_flags *flags, char *number)
{
	int	total_width;

	total_width = flags->width - ft_strlen(number);

	if (flags->minus)
		number = align_to_the_left(number, total_width);
	else
	{
		if ((flags->zero && !flags->precision && !flags->prec_val)
			|| (flags->conversion_type == FLOAT && flags->zero))
			number = pad_with_zeroes(number, total_width);
		else
			number = align_to_the_right(number, total_width);
	}
	return (number);
}
