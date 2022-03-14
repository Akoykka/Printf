/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:12:57 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/14 23:33:45 by akoykka          ###   ########.fr       */
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
	int		conversion_index;
	int		min_field_depth;
	int		minus_flag;		// minus and number		// the actual type of the printable
	va_list va_pointer;
}			t_flags;

// Utils

int	int_len(int number);
void reset_flags(t_flags *modifiers);
// Flag recognition phase


char	*check_sign_flag(t_flags *modifiers, char *temp);
char	*check_minimum_field_of_width(t_flags *modifiers, char *temp);
char	*check_for_space_flag(t_flags *modifiers, char *temp);
char	*check_for_zero_flag(t_flags *modifiers, char *temp);
char	*check_decimal_flag(t_flags *modifiers, char *temp);
size_t	check_for_flags(char *format, t_flags *modifiers);


// conversion functions
void	decimal_conversion(t_flags *modifiers);
// apply phase
void	apply_plus_flag(t_flags *modifiers, int number);
void 	apply_min_field_width(t_flags *modifiers, int number);
void	di_apply_decimal_flag(t_flags *modifiers, int number);
void	di_apply_space_flag(t_flags *modifiers, int number);
void	di_apply_zero_flag(t_flags *modifiers, int number);
#endif
