/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:03:59 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 18:54:49 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	special_putstr(char *number, t_flags *flags)
{
	int		print_amount;
	char	*null_charecter;

	null_charecter = ft_strnew(0);
	check_alloc(null_charecter, number, flags);
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
	check_alloc(number, NULL, flags);
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

void	string_conversion(t_flags *flags)
{
	char				*string;

	string = va_arg(*(flags->va_ptr), char *);
	if (string == NULL)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(string);
	string = s_apply_precision(flags, string);
	if (flags->width > (int)ft_strlen(string))
		string = pad_width(flags, string);
	flags->printf_ret += (int)ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&string);
}

void	pointer_conversion(t_flags *flags)
{
	void				*temp;
	char				*number;
	char				prefix[3];
	char				*free_er;

	temp = va_arg(*(flags->va_ptr), void *);
	number = base_to_ascii((unsigned long long)temp, HEXADECIMAL_BASE);
	check_alloc(number, NULL, flags);
	free_er = number;
	ft_strcpy(prefix, "0x");
	number = ft_strjoin(prefix, number);
	check_alloc(number, NULL, flags);
	ft_strdel(&free_er);
	if (flags->width > (int)ft_strlen(number))
		number = pad_width(flags, number);
	flags->printf_ret += ft_strlen(number);
	ft_putstr(number);
	ft_strdel(&number);
}