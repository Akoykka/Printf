/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:59:01 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/21 15:34:20 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	replace_nb_with_rounded_nb(char **number, char *rounded_nb)
{
	char	*temp;
	char	*free_er;

	free_er = *number;
	temp = ft_strchr(*number, '.');
	ft_memmove(*number, &number[0][temp - *number],
		ft_strlen(&number[0][temp - *number]));
	*number = ft_strjoin(rounded_nb, *number);
	ft_strdel(&free_er);
	ft_strdel(&rounded_nb);
	return ;
}

void	rounding_operation(char *target, char **number)
{
	int		temp;
	char	*rounded_nb;
	char	*decimal_before_target;

	if (*target == '.')
	{
		temp = ft_atoi(*number);
		temp++;
		rounded_nb = ft_itoa(temp);
		replace_nb_with_rounded_nb(number, rounded_nb);
	}
	else
	{
		if (*target == '9')
		{
			decimal_before_target = &number[0][target - *number - 1];
			*target = '0';
			rounding_operation(decimal_before_target, number);
		}
		else
			++*target;
	}
}

int	check_till_the_end(char *number)
{
	while (*number)
	{
		if (*number != '0')
			return (ROUND_UP);
		++number;
	}
	return (NO_ROUNDING);
}

int	bankers_rounding(char *next_decimal, char *target)
{
	if (*target == '.')
		++target;
	if (*next_decimal >= '6' && *next_decimal <= '9')
		return (ROUND_UP);
	if (*next_decimal == '5')
	{
		if (!is_round_nbr(*target))
			return (ROUND_UP);
		else
			return (check_till_the_end(next_decimal + 1));
	}
	return (NO_ROUNDING);
}

int	rounding_check(char *target, char *number)
{
	char	*next_decimal;

	(void)number;
	next_decimal = target + 1;
	if (*next_decimal >= '6' && *next_decimal <= '9')
		return (ROUND_UP);
	if (*target == '.')
		return (bankers_rounding(next_decimal, target - 1));
	return (bankers_rounding(next_decimal, target));
}
