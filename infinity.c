/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:55:59 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/21 16:09:40 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*align_right_inf(char *number, t_flags *flags)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	temp = ft_strnew(1);
	check_alloc(temp, number, flags);
	ft_memset(temp, ' ', 1);
	number = ft_strjoin(temp, number);
	ft_strdel(&temp);
	ft_strdel(&free_er);
	check_alloc(number, NULL, flags);
	return (number);
}

int	check_infinity_and_nan(long double temp, t_flags *flags)
{	
	char	*number;

	if (temp == -1.0 / 0 || temp == 1.0 / 0
		|| temp != temp)
	{	
		number = ft_memalloc(sizeof(char) * 5);
		if (temp == 1.0 / 0)
			ft_strcpy(number, "inf");
		if (temp == 1.0 / 0 && flags->plus)
			ft_strcpy(number, "+inf");
		if (temp == -1.0 / 0)
			ft_strcpy(number, "-inf");
		if (temp != temp)
			ft_strcpy(number, "nan");
		if (flags->space && !flags->plus && !flags->zero && temp == 1.0 / 0)
			number = align_right_inf(number, flags);
		flags->zero = 0;
		if (flags->width > (int)ft_strlen(number))
			number = pad_width(flags, number);
		flags->printf_ret += ft_strlen(number);
		ft_putstr(number);
		ft_strdel(&number);
		return (1);
	}
	return (0);
}
