/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/11 19:53:20 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_conversion(t_flags *flags)
{
	long long			temp;
	char				*number;

	temp = get_arg_di(flags);
	if (temp < 0)
	{
		temp *= -1; // muista min_longlong suojata (ei mahu max longlongiin)
		flags->negative = 1;
	}
	number = base_to_ascii((unsigned long long)temp, DECIMAL_BASE);
	number = apply_precision(flags, number);
	number = apply_space_flag(flags, number);
	number = apply_plus_flag(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);	
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
}

void	unsigned_int_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, DECIMAL_BASE);
	number = apply_hash_flag(flags, number);
	//number = apply_plus_flag(flags, number);
	//number = apply_space_flag(flags, number);
	number = apply_precision(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	//return (1);
}

void	string_conversion(t_flags *flags)
{
	char				*string;

	string = va_arg(*(flags->va_ptr), char *);
	string = s_apply_precision(flags, string);
	flags->printf_ret += (int)ft_strlen(string);
	ft_putstr(string);
	//return (1);
}

void	octal_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, OCTAL_BASE);
	number = apply_hash_flag_oct(flags, number);
	//number = apply_plus_flag(flags, number); ei toimi
	//number = apply_space_flag(flags, number); ei toimi
	number = apply_precision(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	//return (1);
}

void	hexadecimal_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, HEXADECIMAL_BASE);
	number = apply_hash_flag(flags, number);
	//number = apply_plus_flag(flags, number);
	//number = apply_space_flag(flags, number);
	number = apply_precision(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	//if (!is_number_just_space(number))
		//number = apply_hash_flag_hex(flags, number);
	flags->printf_ret += ft_strlen(number);
	if (flags->conversion_type == HEX_UPPER)
		toupper_everything(number);
	ft_putstr(number);
	//return (1);
}

void	charecter_conversion(t_flags *flags)
{
	unsigned int				temp;
	char						*number;

	temp = va_arg(*(flags->va_ptr), unsigned int);
	number = ft_strnew(1);
	number[0] = temp;
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	//return (1);
}

void	pointer_conversion(t_flags *flags)
{
	void				*temp;
	char				*number = NULL;
	char				*prefix;
	char				*free_er;

	free_er = number;
	temp = va_arg(*(flags->va_ptr), void *);
	number = base_to_ascii((unsigned long long)temp, HEXADECIMAL_BASE);
	prefix = ft_strnew(2);
	ft_strcpy(prefix, "0x");
	number = ft_strjoin(prefix, number);
	//ft_strdel(&free_er);
	//ft_strdel(&temp);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	//return (1);
}
void	percentage_conversion(t_flags *flags)
{
	char	*percentage;

	(void)flags;
	percentage = ft_strnew(1);
	ft_memset(percentage, '%', 1);
	if (flags->width > (int)ft_strlen(percentage))
		percentage = pad_width(flags, percentage);
	flags->printf_ret += ft_strlen(percentage);
	ft_putstr(percentage);
	//return (1);
}

void	float_conversion(t_flags *flags)
{
	long double	temp;
	char		*number;

	temp = get_arg_f(flags);
	number = float_to_ascii(flags, temp);
	number = apply_plus_flag(flags, number);
	number = apply_precision_f(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	//return (1);
}

// Muuta arvo





/*
muuta arvo hexadecimaaliksi niin se nayttaa osoittteen.
if precision then no zero flag 

//	if minus flag no zero flag

// if plus no space flag

# works with 
s
First + or - or # 0 flag must be after that

width must be before preciesion

precision comes last.



first apply precision 

then apply + or space

calculate width and apply - 0 or none flag
*/