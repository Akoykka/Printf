/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:05:55 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/14 13:07:57 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int number)
{
	int	lenght;

	lenght = 0;
	while (number != 0)
	{
		number = number / 10;
		++lenght;
	}
	return (lenght);
}
