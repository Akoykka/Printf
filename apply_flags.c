/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:10:14 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 19:52:14 by akoykka          ###   ########.fr       */
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
		check_alloc(temp, number, flags);
		if ((flags->conversion_type == HEX
				|| flags->conversion_type == HEX_UPPER)
			&& !is_value_zero(number))
		{
			ft_strcpy(temp, "0x");
			number = ft_strjoin(temp, number);
			ft_strdel(&free_er);
		}
		if (flags->conversion_type == OCTAL && *number != '0')
		{
			temp[0] = '0';
			number = ft_strjoin(temp, number);
			ft_strdel(&free_er);
		}
		ft_strdel(&temp);
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
		check_alloc(temp, number, flags);
		if (*number != '0' && (flags->conversion_type == HEX
				|| flags->conversion_type == HEX_UPPER))
		{
			ft_strcpy(temp, "0x");
			number = ft_strjoin(temp, number);
			ft_strdel(&free_er);
		}
		if (flags->conversion_type == OCTAL && *number != '0')
		{
			temp[0] = '0';
			number = ft_strjoin(temp, number);
			ft_strdel(&free_er);
		}
		ft_strdel(&temp);
	}
	check_alloc(number, NULL, flags);
	return (number);
}

char	*apply_plus_flag(t_flags *flags, char *number)
{
	char	*temp;
	char	*free_er;

	free_er = number;
	if (flags->plus || flags->negative)
	{
		temp = ft_strnew(1);
		check_alloc(temp, number, flags);
		if (!flags->negative)
			ft_memset(temp, '+', 1);
		if (flags->negative)
			ft_memset(temp, '-', 1);
		number = ft_strjoin(temp, number);
		ft_strdel(&temp);
		ft_strdel(&free_er);
	}
	check_alloc(number, NULL, flags);
	return (number);
}

char	*apply_space_flag(t_flags *flags, char *number)
{
	if (flags->space
		&& !flags->plus
		&& !flags->negative
		&& !is_number_just_space(number))
		number = align_to_right(number, 1, flags);
	return (number);
}

int	is_value_zero(char *number)
{
	while (*number)
	{
		if (*number != '0' && *number != ' ')
			return (0);
		++number;
	}
	return (1);
}
