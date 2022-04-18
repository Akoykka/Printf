/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:04:37 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 19:32:23 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*align_to_right(char *number, int width, t_flags *flags)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(width);
	check_alloc(temp, number, flags);
	ft_memset(temp, ' ', width);
	number = ft_strjoin(temp, number);
	ft_strdel(&temp);
	ft_strdel(&free_er);
	check_alloc(number, NULL, flags);
	return (number);
}

void	add_zeros_between_sign(char *number, char *temp)
{
	char	*temp2;

	if (*number == '-' || *number == '+' || *number == ' ')
	{
		*temp = *number;
		*number = '0';
	}
	temp2 = ft_strchr(number, 'x');
	if (temp2 != NULL)
	{
		*temp2 = '0';
		temp[1] = 'x';
	}
}

char	*pad_with_zeroes(char *number, int width, t_flags *flags)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(width);
	check_alloc(temp, number, flags);
	ft_memset(temp, '0', width);
	add_zeros_between_sign(number, temp);
	if (ft_strlen(number) == 0)
		ft_memset(temp, ' ', width);
	number = ft_strjoin(temp, number);
	ft_strdel(&temp);
	ft_strdel(&free_er);
	check_alloc(number, NULL, flags);
	return (number);
}

char	*align_to_left(char *number, int width, t_flags *flags)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(width);
	check_alloc(temp, number, flags);
	ft_memset(temp, ' ', width);
	number = ft_strjoin(number, temp);
	ft_strdel(&temp);
	ft_strdel(&free_er);
	check_alloc(number, NULL, flags);
	return (number);
}

char	*pad_width(t_flags *flags, char *number)
{
	int	total_width;

	total_width = flags->width - ft_strlen(number);
	if (flags->minus)
		number = align_to_left(number, total_width, flags);
	else
	{
		if ((flags->zero && !flags->precision && !flags->prec_val)
			|| (flags->conversion_type == FLOAT && flags->zero))
			number = pad_with_zeroes(number, total_width, flags);
		else
			number = align_to_right(number, total_width, flags);
	}
	return (number);
}
