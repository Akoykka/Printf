/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:20:08 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 12:13:21 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_arg_di(t_flags *flags)
{
	int temp;

	if (flags->hh)
	{
		temp = va_arg(*(flags->va_ptr), int);
		temp = (signed char)temp;
		return (temp);
	}
	if (flags->h)
	{
		temp = va_arg(*(flags->va_ptr), int);
		temp = (signed short)temp;
		return (temp);
	}
	if (flags->ll)
		return (va_arg(*(flags->va_ptr), long long));
	if (flags->l)
		return (va_arg(*(flags->va_ptr), long));
	return (va_arg(*(flags->va_ptr), int));
}

unsigned long long	get_arg_oux(t_flags *flags)
{
	int temp;

	if (flags->hh)
	{
		temp = va_arg(*(flags->va_ptr), unsigned int);
		temp = (unsigned char)temp;
		return (temp);
	}
	if (flags->h)
	{
		temp = va_arg(*(flags->va_ptr), unsigned int);
		temp = (unsigned short)temp;
		return (temp);
	}
	if (flags->ll)
		return (va_arg(*(flags->va_ptr), unsigned long long));
	if (flags->l)
		return (va_arg(*(flags->va_ptr), unsigned long));
	return (va_arg(*(flags->va_ptr), unsigned int));
}

long double	get_arg_f(t_flags *flags)
{
	if (flags->l)
		return (va_arg(*(flags->va_ptr), double));
	if (flags->ll)
		return (va_arg(*(flags->va_ptr), long double));
	return (va_arg(*(flags->va_ptr), double));
}
