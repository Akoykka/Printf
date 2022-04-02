/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:12:57 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/02 17:59:08 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SUCCESS 0
# define FAIL 1
# define HEXADECIMAL_BASE 16
# define OCTAL_BASE 8
# define DECIMAL_BASE 10
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

/// MAIN
int					main(void);

void				print_next_parameter(char *format, va_list *va_pointer);
int				ft_printf(char *format, ...);
char				*cpy_format(char *format);
void				conversion_type_table(int index, va_list *va_pointer, char *format);
void				print_next_parameter(char *format, va_list *va_pointer);

// get type type
long long			get_arg_di(va_list *va_pointer, char *format);
unsigned long long	get_arg_oux(va_list *va_pointer, char *format);

// conversion functions
void				decimal_conversion(va_list *va_pointer, char *format);
void				string_conversion(va_list *va_pointer, char *format);
void				octal_conversion(va_list *va_pointer, char *format);
void				hexadecimal_conversion(va_list *va_pointer, char *format);
void				charecter_conversion(va_list *va_pointer, char *format);
void				percentage_conversion(va_list *va_pointer, char *format);
void				pointer_conversion(va_list *va_pointer, char *format);
void				hexadecimal_conversion_uppercase(va_list *va_pointer, char *format);
void				unsigned_int_conversion(va_list *va_pointer, char *format);

// apply flags
char				*check_hash_flag(char *format, char *number);
char				*check_plus_flag(char *format, char *number);
char				*check_space_flag(char *format, char *number);
char				*apply_precision(char *format, char *number);
char				*s_apply_precision(char *format, char *string);

// PADDINGTON
char				*align_to_the_left(char *number, int width);
char				*align_to_the_right(char *number, int width);
char				*pad_with_zeroes(char *number, int width);
char				*pad_width(char *format, char *number, int width);
///// utils PADDINTON
int					get_min_width_value(char *format);
int					first_digit_is_zero(char *format);

// apply flags string
char				*s_apply_decimal_flag(char *pointer);
void				s_apply_and_print_minus_flag(char *pointer);
void				s_apply_and_print_width(char *pointer);

/// UTILS
void				print_result(char *format, char *result);
char				*base_to_ascii(unsigned long long number, int base);
char				number_to_char(unsigned long long number);
char				longlong_to_char(long long number);
char				*longlong_to_ascii(long long number, int base);
void				toupper_everything(char *number);
#endif
