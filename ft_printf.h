/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:12:57 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/10 14:31:45 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SUCCESS 0
# define FAIL 1
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	int		sign_flag;		// ( + ) show + or minus in the front overrides space
	int		zero_flag;		// (0 and number)
	int		decimal_flag;	 // period and number
	int		space_flag;	// space and number
	int		minus_flag;		// minus and number
	char	type[30];			// the actual type of the printable
}			t_flags;

#endif
