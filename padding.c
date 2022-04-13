/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:04:37 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/13 11:19:57 by akoykka          ###   ########.fr       */
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
	flags->width -= ft_strlen(number);

	if (flags->minus)
		number = align_to_the_left(number, flags->width);
	else
	{
		if (flags->zero && (!flags->precision && !flags->prec_val))
			number = pad_with_zeroes(number, flags->width);
		else
			number = align_to_the_right(number, flags->width);
	}
	return (number);
}
