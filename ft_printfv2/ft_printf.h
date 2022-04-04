/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:12:57 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/22 10:41:01 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SUCCESS 0
# define FAIL 1
# define HEXADEC_BASE 16
# define OCTAL_BASE 8
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	char	type[10];
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		sign_flag;		// ( + ) show + or minus in the front overrides space
	int		zero_flag;		// (0 and number)
	int		decimal_flag;	 // period and number
	int		space_flag;	// space and number
	int		conversion_index;
	int		min_field_depth; // just number
	int		minus_flag;		// minus and number		// the actual type of the printable
	va_list va_pointer;
}			t_flags;

// Utils

int		int_len(int number);
void	reset_flags(t_flags *modifiers);
char	*convert_number_to_base(unsigned long long number, int base);
char	number_to_char(unsigned long long number);

// Flag recognition phase

char	*check_sign_flag(t_flags *modifiers, char *temp);
char	*check_minimum_field_of_width(t_flags *modifiers, char *temp);
char	*check_for_space_flag(t_flags *modifiers, char *temp);
char	*check_for_zero_flag(t_flags *modifiers, char *temp);
char	*check_decimal_flag(t_flags *modifiers, char *temp);
char	*check_for_length(t_flags *modifiers, char *format);
size_t	check_for_flags(char *format, t_flags *modifiers);

// conversion functions
void	octal_conversion(t_flags *modifiers);
void	decimal_conversion(t_flags *modifiers);
void	string_conversion(t_flags *modifiers);
void	hexadecimal_conversion(t_flags *modifiers);
// apply phase decimals
void	di_apply_plus_flag(t_flags *modifiers, int number);
void	di_apply_min_field_width(t_flags *modifiers, int number);
void	di_apply_decimal_flag(t_flags *modifiers, int number);
void	di_apply_space_flag(t_flags *modifiers, int number);
void	di_apply_zero_flag(t_flags *modifiers, int number);
// apply phase string
char	*s_apply_decimal_flag(t_flags *modifiers, char *pointer);
void	s_apply_and_print_minus_flag(t_flags *modifiers, char *pointer);
void	s_apply_and_print_width(t_flags *modifiers, char *pointer);

// apply phase octals

void	o_apply_minus_flag(t_flags *modifiers, char **number);
void	o_apply_decimal_flag(t_flags *modifiers, char **number);
void	o_apply_min_field_width(t_flags *modifiers, char **number);
void	o_apply_zero_flag(t_flags *modifiers, char **number);
void	o_apply_sign_flag(t_flags *modifiers, char **number);
void	o_apply_space_flag(t_flags *modifiers, char **number);

// apply phase hexadecimal

// same as octal functions

#endif
