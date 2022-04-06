/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:10:14 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/06 16:24:01 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_hash_flag(char *format, char *number)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	if (ft_strchr(format, '#'))
	{
		temp = ft_strnew(2);
		ft_memset(temp, '\0', 2);
		if ((ft_strchr(format, 'X') || ft_strchr(format, 'x'))
			&& *number != 0)
		{
			ft_strcpy(temp, "0x");
			number = ft_strjoin(temp, number);
			//ft_strdel(&free_er);
		}
		if (ft_strchr(format, 'o') && *number != '0')
		{
			temp[0] = '0';
			number = ft_strjoin(temp, number);
			//ft_strdel(&free_er);
		}
		//ft_strdel(&temp);
	}
	return (number);
}

char	*check_plus_flag(char *format, char *number)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	if (*format == '+' && *number != '-')
	{
		temp = ft_strnew(1);
		ft_memset(temp, '+', 1);
		number = ft_strjoin(temp, number);
		//ft_strdel(&temp);
		//ft_strdel(&free_er);
	}
	return (number);
}

char	*check_space_flag(char *format, char *number)
{
	if (ft_strchr(format, ' ') && !ft_strchr(format, '+'))
		align_to_the_right(number, 1);
	return (number);
}

char	*apply_precision(char *format, char *number)
{
	char	*temp;
	int		precision;

	precision = 0;
	temp = ft_strchr(format, '.');
	if (temp)
	{
		if (ft_isdigit(*(temp + 1)))
			precision = ft_atoi(temp + 1);
	}
	if (precision > (int)ft_strlen(number))
	{
		precision -= (int)ft_strlen(number);
		number = pad_with_zeroes(number, precision);
	}
	return (number);
}

int	get_min_width_value(char *format)
{
	while (*format != '.' && *format)
	{
		if (ft_isdigit(*format))
			return (ft_atoi(format));
		++format;
	}
	return (0);
}

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
