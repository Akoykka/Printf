/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:10:14 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/22 11:21:49 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_apply_sign_flag(t_flags *modifiers, char **number)
{
	char	*temp;
	char	*free_er;

	free_er = *number;
	if (**number != '-' && modifiers->sign_flag)
	{
		temp = ft_strnew(1);
		temp[0] = '+';
		*number = ft_strjoin(temp, *number);
		free(temp);
		free(free_er);
	}
}

void	o_apply_min_field_width(t_flags *modifiers, char **number)
{
	int		min_width;
	char	*temp;
	char	*free_er;

	free_er = *number;
	min_width = modifiers->min_field_depth - (ft_strlen(*number));
	if (min_width > 0)
	{
		temp = ft_strnew(min_width);
		ft_memset(temp, ' ', min_width);
		*number = ft_strjoin(temp, *number);
		free(temp);
		free(free_er);
	}
}

void	o_apply_zero_flag(t_flags *modifiers, char **number)
{
	int		req_extra_zeros;
	char	*temp;
	char	*free_er;

	free_er = *number;
	req_extra_zeros = modifiers->zero_flag - (ft_strlen(*number));
	if (req_extra_zeros > 0)
	{
		temp = ft_strnew(req_extra_zeros);
		ft_memset(temp, '0', req_extra_zeros);
		*number = ft_strjoin(temp, *number);
		free(temp);
		free(free_er);
	}
}

void	o_apply_decimal_flag(t_flags *modifiers, char **number)
{
	int		req_extra_zeros;
	char	*temp;
	char	*free_er;

	free_er = *number;
	req_extra_zeros = modifiers->decimal_flag - (ft_strlen(*number));
	if (req_extra_zeros > 0)
	{
		temp = ft_strnew(req_extra_zeros);
		ft_memset(temp, '0', req_extra_zeros);
		*number = ft_strjoin(temp, *number);
		free(temp);
		free(free_er);
	}
}

void	o_apply_minus_flag(t_flags *modifiers, char **number)
{
	int		offset_to_left;
	char	*temp;
	char	*free_er;

	free_er = *number;
	offset_to_left = modifiers->minus_flag - ft_strlen(*number);
	if (offset_to_left > 0)
	{
		temp = ft_strnew(offset_to_left);
		ft_memset(temp, ' ', offset_to_left);
		*number = ft_strjoin(*number, temp);
		free(temp);
		free(free_er);
	}
}

void	o_apply_space_flag(t_flags *modifiers, char **number)
{
	int		offset_to_right;
	char	*temp;
	char	*free_er;

	free_er = *number;
	offset_to_right = modifiers->space_flag - ft_strlen(*number);
	if (offset_to_right > 0)
	{
		temp = ft_strnew(offset_to_right);
		ft_memset(temp, ' ', offset_to_right);
		*number = ft_strjoin(*number, temp);
		free(temp);
		free(free_er);
	}
}

////////////

//if precision then no zero flag 

//	if minus flag no zero flag

// if plus no space flag both are not valid :D:D