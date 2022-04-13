/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/13 10:40:08 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char *add_minus(char *number)
{
	char	*minus;
	char	*free_er;

	minus = ft_strdup("-");
	free_er = number;

	number = ft_strjoin(minus, number);
	//ft_strdel(minus);
	//ft_strdel(free_er);


	return (number);
}



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
	//if (flags->negative)
		//number = add_minus(number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
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
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	string_conversion(t_flags *flags)
{
	char				*string;

	string = va_arg(*(flags->va_ptr), char *);
	if (string == NULL)
	{
		ft_putstr("(null)");
		flags->printf_ret += 6;
		return ;
	}
	string = ft_strdup(string);
	string = s_apply_precision(flags, string);

	if (flags->width > (int)ft_strlen(string))
		string = pad_width(flags, string);
	flags->printf_ret += (int)ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&string);
}

void	octal_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, OCTAL_BASE);
	//number = apply_plus_flag(flags, number); ei toimi
	//number = apply_space_flag(flags, number); ei toimi
	number = apply_precision(flags, number);
	number = apply_hash_flag_oct(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	hexadecimal_conversion(t_flags *flags)
{
	char				*number;
	unsigned long long	temp;

	temp = get_arg_oux(flags);
	number = base_to_ascii(temp, HEXADECIMAL_BASE);

	//number = apply_plus_flag(flags, number);
	//number = apply_space_flag(flags, number);
	number = apply_precision(flags, number);
	number = apply_hash_flag(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	//if (!is_number_just_space(number))
		//number = apply_hash_flag_hex(flags, number);
	flags->printf_ret += ft_strlen(number);
	if (flags->conversion_type == HEX_UPPER)
		toupper_everything(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	charecter_conversion(t_flags *flags)
{
	int							temp;
	char						*number;

	temp = va_arg(*(flags->va_ptr), int);
	number = ft_strnew(2);
	if (temp == '\0')
	{
		ft_strcpy(number, "^@");
		flags->printf_ret--;
		flags->width++;
	}
	else
		number[0] = temp;
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}

void	pointer_conversion(t_flags *flags)
{
	void				*temp;
	char				*number;
	char				prefix[3];
	char				*free_er;

	temp = va_arg(*(flags->va_ptr), void *);
	number = base_to_ascii((unsigned long long)temp, HEXADECIMAL_BASE);
	free_er = number;
	ft_strcpy(prefix, "0x");
	number = ft_strjoin(prefix, number);
	ft_strdel(&free_er);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
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
	ft_strdel(&percentage);
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
	ft_strdel(&number);
}
