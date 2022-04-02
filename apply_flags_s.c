/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:39:51 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/02 13:52:34 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_apply_precision(char *format, char *string)
{
	size_t	max_str_len;
	char	*temp;
	char	*free_er;

	max_str_len = 0;
	free_er = string;
	temp = strchr(format, '.');
	if (temp)
	{
		if (ft_isdigit(*(temp + 1)))
			max_str_len = ft_atoi(temp + 1);
		string = ft_strndup(string, max_str_len);
		//ft_strdel(&free_er);
	}
	return (string);
}
/*
void	s_apply_and_print_minus_flag(char *format, char *string)
{	
	int	loop;
	int	minus_flag_value;

	if (strchr(format, '-'))
	{
		minus_flag_value = ft_atoi(strchr(format, '-') + 1);
		loop = minus_flag_value - (int)strlen(string);
		ft_putstr(string);
		while (loop-- > 0)
			ft_putchar(' ');
	}
}

void	s_apply_and_print_width(char *format, char *string)
{
	int	loop;
	int	print_width_value;

	if (ft_isdigit(format[0])
	{
		print_width_value = ft_atoi(&format[0]);
		loop = print_width_value - (int)ft_strlen(string);
		while (loop-- > 0)
			ft_putchar(' ');
	}	
	ft_putstr(string);
}
*/