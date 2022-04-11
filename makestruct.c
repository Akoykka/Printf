/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:18:23 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/11 16:21:11 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struct_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->prec_val = 0;
	flags->negative = 0;
	flags->ll = 0;
	flags->l = 0;
	flags->h = 0;
	flags->hh = 0;
	flags->conversion_type = 12;
}

void	set_rest_flag_values(char *format, t_flags *flags)
{
	char	*temp;

	temp = ft_strchr(format, '.');
	if (temp)
	{
		flags->precision = 1;
		if (ft_isdigit(*(temp + 1)))
			flags->prec_val = ft_atoi(temp + 1);
	}
	if (ft_strchr(format, '+') != NULL)
		flags->plus = 1;
	if (ft_strchr(format, '-') != NULL)
		flags->minus = 1;
	if (ft_strchr(format, ' ') != NULL)
		flags->space = 1;
	if (ft_strchr(format, '#') != NULL)
		flags->hash = 1;
	while (*format != '.' && *format)
	{
		if (ft_isdigit(*format))
		{
			flags->width = ft_atoi(format);
			return ;
		}
		++format;
	}
}

void	set_zero_flag(char *format, t_flags *flags)
{
	while (*format && *format != '.' && !ft_isdigit(*format))
		++format;
	if (*format == '0')
		flags->zero = 1;
}

void	set_lenght_and_conversion_flags(char *format, t_flags *flags)
{
	char	available_conversions[12];
	int		i;

	i = 0;
	if (ft_strstr(format, "hh"))
		flags->hh = 1;
	if (ft_strstr(format, "h"))
		flags->h = 1;
	if (ft_strstr(format, "ll"))
		flags->ll = 1;
	if (ft_strstr(format, "l"))
		flags->l = 1;
	if (ft_strstr(format, "L"))
		flags->ll = 1;
	ft_strcpy(available_conversions, "cspdiuoxXf%");
	while (available_conversions[i])
	{
		if (ft_strchr(format, available_conversions[i]) != NULL)
			flags->conversion_type = i;
		++i;
	}
}

int	get_flag_values(char *format, t_flags *flags)
{	
	int	format_lenght;

	format_lenght = ft_strlen(format);
	reset_struct_flags(flags);
	set_lenght_and_conversion_flags(format, flags);
	set_zero_flag(format, flags);
	set_rest_flag_values(format, flags);
	//free(&format);
	return (format_lenght);
}
