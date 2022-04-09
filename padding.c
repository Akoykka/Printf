/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:04:37 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/10 00:04:37 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*align_to_the_right(char *number, t_flags *flags)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(flags->width);
	ft_memset(temp, ' ', flags->width);
	number = ft_strjoin(temp, number);
	//ft_strdel(&temp);
	//ft_strdel(&free_er);
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


char	*pad_with_zeroes(char *number, t_flags *flags)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(flags->width);
	ft_memset(temp, '0', flags->width);
	if (is_number_just_space(number))
		ft_memset(temp, ' ', flags->width);
	number = ft_strjoin(temp, number);
	//ft_strdel(&temp);
	//ft_strdel(&free_er);
	return (number);
}

char	*align_to_the_left(char *number, t_flags *flags)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(flags->width);
	ft_memset(temp, ' ', flags->width);
	number = ft_strjoin(number, temp);
	//ft_strdel(&temp);
	//ft_strdel(&free_er);
	return (number);
}

char	*pad_width(char *number, t_flags *flags)
{
	flags->width -= ft_strlen(number);

	if (flags->minus)
		number = align_to_the_left(number, flags->width);
	else
	{
		if (flags->zero)
			number = pad_with_zeroes(number, flags->width);
		else
			number = align_to_the_right(number, flags->width);
	}
	return (number);
}
