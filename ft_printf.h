/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:12:57 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/10 00:04:46 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SUCCESS 0
# define ROUND_UP 1
# define NO_ROUNDING 0
# define FAIL 1
# define HEXADECIMAL_BASE 16
# define OCTAL_BASE 8
# define DECIMAL_BASE 10
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"


typedef struct s_flags
{
	int		plus;
	int		minus;
	int		space;
	int		zero;
	int		hash;
	int		width;
	int		precision;
	int		prec_val;
	int		negative;
	int		ll;
	int		l;
	int		h;
	int		hh;
	int		printf_ret;
	int		conversion_type;
	va_list	*va_ptr;
}				t_flags;


int					ft_printf(const char *format, ...);

char				*cpy_format(char *format);
void				dispatch_table(t_flags *flags);

// get type type
long long			get_arg_di(t_flags *flags);
unsigned long long	get_arg_oux(t_flags *flags);
long double			get_arg_f(t_flags *flags);

// conversion functions
int					decimal_conversion(t_flags *flags);
int					string_conversion(t_flags *flags);
int					octal_conversion(t_flags *flags);
int					hexadecimal_conversion(t_flags *flags);
int					charecter_conversion(t_flags *flags);
int					percentage_conversion(t_flags *flags);
int					pointer_conversion(t_flags *flags);
int					hexadecimal_conversion_uppercase(t_flags *flags);
int					unsigned_int_conversion(t_flags *flags);
int					float_conversion(t_flags *flags);

// apply flags
char				*apply_hash_flag(t_flags *flags, char *number);
char				*apply_plus_flag(t_flags *flags, char *number);
char				*apply_space_flag(t_flags *flags, char *number);
char				*apply_precision(t_flags *flags, char *number);
char				*s_apply_precision(t_flags *flags, char *string);
// Apply Flags for floats
char				*decimals_to_ascii(long double number);
char				*float_to_ascii(long double number);
char				*apply_precision_f(t_flags *flags, char *number);

/// ROUNDING FOR FLOATS
char				*rounding_operation(char *target, char *number);
char				*replace_nb_with_rounded_nb(char *number, char *rounded_nb);
int					rounding_check(char *number);
int					bankers_rounding(char number);
int					is_round_nbr(char number);

// PADDINGTON
char				*align_to_the_left(char *number, t_flags *flags);
char				*align_to_the_right(char *number, t_flags *flags);
char				*pad_with_zeroes(char *number, t_flags *flags);
char				*pad_width(char *number, t_flags *flags);
// apply flags string
char				*s_apply_decimal_flag(char *pointer);

/// UTILS
char				*base_to_ascii(unsigned long long number, int base);
char				number_to_char(unsigned long long number);
void				toupper_everything(char *number);
int					is_number_just_space(char *number);
#endif
