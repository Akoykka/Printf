/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/14 20:37:43 by akoykka          ###   ########.fr       */
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
		string = strdup("(null)");
	else
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

void special_putstr(char *number, t_flags *flags)
{
	int		print_amount;
	char	*null_charecter;

	null_charecter = ft_strnew(0);
	print_amount = 1;
	flags->width--;
	if (flags->width > 1)
		print_amount = flags->width;
	while (*number)
	{
		if (*number == '^')
		{
			write(1, null_charecter, 1);
			number += 2;
		}
		else
			write(1, number++, 1);
	}
	flags->printf_ret += print_amount;
	ft_strdel(&null_charecter);
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
		flags->width++;
	}
	else
		number[0] = temp;
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	if (ft_strstr(number, "^@"))
	{
		special_putstr(number, flags);
		free(number);
		return ;
	}
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
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
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
	number = apply_precision_f(flags, number);
	number = apply_space_flag(flags, number);
	number = apply_plus_flag(flags, number);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}
