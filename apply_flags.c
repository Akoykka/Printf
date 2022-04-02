/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:10:14 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/02 15:34:28 by akoykka          ###   ########.fr       */
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

/*
	if (if first digit is 0 in the format)
	zeros in the beginning after the  if minus then remember

	return()
	


	
	}
} 
//if precision then no zero flag 

//	if minus flag no zero flag

// if plus no space flag both are not valid :D:D

if 
	else if

	else
////////////

char	*apply_zero_flag(char *format, char *number)
{
	int			req_extra_zeros;
	char		*temp;
	char		*free_er;

	if (format[0] == '0')
	{
		free_er = number;
		req_extra_zeros = atoi(&format[1]) - (ft_strlen(number));
		if (req_extra_zeros > 0)
		{
			temp = ft_strnew(req_extra_zeros);
			ft_memset(temp, '0', req_extra_zeros);
			number = ft_strjoin(temp, number);
			free(temp);
			free(free_er);
		}
	}
	return (number);
}

char	*apply_sign_flag(char *format, char *number)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	if (*number != '-' && format[0] == '+')
	{
		temp = ft_strnew(1);
		temp[0] = '+';
		*number = ft_strjoin(temp, number);
		free(temp);
		free(free_er);
	}
	return (number);
}

char	*apply_min_field_width(char *format, char *number)
{
	int		min_width;
	char	*temp;
	char	*free_er;

	free_er = number;
	if (ft_isdigit(format[0] && format[0] != '0'))
	{
		min_width = ft_atoi(&format[0] - (ft_strlen(number)));
		if (min_width > 0)
		{
			temp = ft_strnew(min_width);
			ft_memset(temp, ' ', min_width);
			number = ft_strjoin(temp, number);
			free(temp);
			free(free_er);
		}
	}
	return (number);
}

char	*apply_zero_flag(char *format, char *number)
{
	int			req_extra_zeros;
	char		*temp;
	char		*free_er;

	if (format[0] == '0')
	{
		free_er = number;
		req_extra_zeros = atoi(&format[1]) - (ft_strlen(number));
		if (req_extra_zeros > 0)
		{
			temp = ft_strnew(req_extra_zeros);
			ft_memset(temp, '0', req_extra_zeros);
			number = ft_strjoin(temp, number);
			free(temp);
			free(free_er);
		}
	}
	return (number);
}

char	*apply_decimal_flag(char *format, char *number)
{
	int		req_xtra_zeros;
	char	*temp;
	char	*free_er;

	free_er = number;
	if (ft_strchr(format, '.'))
	{
		req_xtra_zeros = atoi(ft_strchr(format, '.') + 1) - (ft_strlen(number));
		if (req_xtra_zeros > 0)
		{
			temp = ft_strnew(req_xtra_zeros);
			ft_memset(temp, '0', req_xtra_zeros);
			*number = ft_strjoin(temp, number);
			free(temp);
			free(free_er);
		}
	}	
	return (number);
}

char	*apply_minus_flag(char *format, char *number)
{
	int		offset_to_left;
	char	*temp;
	char	*free_er;

	if (format[0] == '-')
	{
		free_er = number;
		offset_to_left = ft_atoi(&format[1]) - ft_strlen(number);
		if (offset_to_left > 0)
		{
			temp = ft_strnew(offset_to_left);
			ft_memset(temp, ' ', offset_to_left);
			number = ft_strjoin(number, temp);
			free(temp);
			free(free_er);
		}
	}
	return (number);
}

char	*apply_space_flag(char *format, char *number)
{
	int		offset_to_right;
	char	*temp;
	char	*free_er;

	free_er = number;
	if (ft_strchr(format, ' '))
	{
		temp = ft_strnew(1);
		ft_memset(temp, ' ', 1);
		number = ft_strjoin(temp, number);
		free(temp);
		free(free_er);
	}
	return (number);
}

*/
