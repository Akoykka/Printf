/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:10:14 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/11 19:53:19 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_hash_flag(t_flags *flags, char *number)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	if (flags->hash)
	{
		temp = ft_strnew(2);
		ft_memset(temp, '\0', 2);
		if (*number != '0'
			&& (flags->conversion_type == HEX
				|| flags->conversion_type == HEX_UPPER))
		{
			ft_strcpy(temp, "0x");
			number = ft_strjoin(temp, number);
			//ft_strdel(&free_er);
		}
		if (flags->conversion_type == OCTAL && *number != '0')
		{
			temp[0] = '0';
			number = ft_strjoin(temp, number);
			//ft_strdel(&free_er);
		}
		//ft_strdel(&temp);
	}
	return (number);
}

char	*apply_hash_flag_oct(t_flags *flags, char *number)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	if (flags->hash)
	{
		temp = ft_strnew(2);
		if (*number != '0'
			&& (flags->conversion_type == HEX
				|| flags->conversion_type == HEX_UPPER))
		{
			ft_strcpy(temp, "0x");
			number = ft_strjoin(temp, number);
			//ft_strdel(&free_er);
		}
		if (flags->conversion_type == OCTAL && *number != '0')
		{
			temp[0] = '0';
			number = ft_strjoin(temp, number);
			//ft_strdel(&free_er);
		}
		//ft_strdel(&temp);
	}
	return (number);
}

char	*apply_hash_flag_hex(t_flags *flags, char *number)
{
	char	*temp;
	char	*free_er;
	size_t	i;

	i = 0;
	if (flags->hash)
	{
		free_er = number;
		temp = (char *)ft_memalloc(sizeof(char) * (flags->width + 2));
		while (number[i] == ' ')
			++i;
		ft_strncpy(temp, number, i);
		ft_strcat(temp, "0x");
		ft_strcat(temp, &number[i]);
		//ft_strdel(&free_er);
		//ft_strdel(&temp);
		return (temp);
	}
	return (number);
}



char	*apply_plus_flag(t_flags *flags, char *number)
{
	char	*temp;
	//char	*free_er;

	//free_er = number;
	
	if (flags->plus || flags->negative)
	{
		temp = ft_strnew(1);
		if (!flags->negative)
			ft_memset(temp, '+', 1);
		if (flags->negative)
			ft_memset(temp, '-', 1);
		number = ft_strjoin(temp, number);
		//ft_strdel(&temp);
		//ft_strdel(&free_er);
	}
	return (number);
}

char	*apply_space_flag(t_flags *flags, char *number)
{
	if (flags->space
		&& !flags->plus
		&& !flags->negative
		&& !is_number_just_space(number))
		number = align_to_the_right(number, 1);
	return (number);
}

int is_value_zero(char *number)
{
	while (*number)
	{
		if (*number != '0' && *number != ' ')
			return (0);
		++number;
	}
	return (1);
}

char	*apply_precision(t_flags *flags, char *number)
{
	if (flags->precision)
	{
		if (!flags->prec_val && is_value_zero(number))
			return (ft_memset(number, '\0', ft_strlen(number)));
		if (flags->prec_val > (int)ft_strlen(number))
		{
		flags->prec_val -= (int)ft_strlen(number);
		number = pad_with_zeroes(number, flags->prec_val);
		}
	}
	return (number);
}

char	*s_apply_precision(t_flags *flags, char *string)
{
	char	*free_er;

	free_er = string;
	if (flags->precision)
	{
		if (flags->prec_val < (int)ft_strlen(string))
		string = ft_strndup(string, flags->prec_val);
		//ft_strdel(&free_er);
	}
	return (string);
}
