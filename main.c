/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:06 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/10 14:46:08 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int number)
{
	int	lenght;

	lenght = 0;
	while (number != 0)
	{
		number = number / 10;
		++lenght;
	}
	return (lenght);
}

char	*check_sign_flag(t_flags *modifiers, char *temp)
{
	if (*temp == '+')
	{
		modifiers->sign_flag = 1;
		return (++temp);
	}
	if (*(temp + 1) == '-')
	{
		modifiers->sign_flag = -1;
		return (++temp);
	}
	return (temp);
}

char	*check_for_space_flag(t_flags *modifiers, char *temp)
{
	if (*temp == ' ')
	{
		++temp;
		modifiers->space_flag = ft_atoi(temp);
		temp = temp + int_len(modifiers->space_flag);
	}
	return (temp);
}

char	*check_for_zero_flag(t_flags *modifiers, char *temp)
{
	if (*temp == '0')
	{
		++temp;
		modifiers->zero_flag = ft_atoi(temp);
		temp = temp + int_len(modifiers->zero_flag);
	}
	return (temp);
}

char	*check_decimal_flag(t_flags *modifiers, char *temp)
{
	if (*temp == '.')
	{
		++temp;
		modifiers->decimal_flag = ft_atoi(temp);
		temp = temp + int_len(modifiers->decimal_flag);
	}
	return (temp);
}

int	check_for_type(t_flags *modifiers, char *temp)
{
	if (*temp == 'c')
	{
		ft_strcpy(modifiers->type, "char");
		return (SUCCESS);
	}
	if (*temp == 's')
	{
		ft_strcpy(modifiers->type, "string");
		return (SUCCESS);
	}
	if (*temp == 'd')
	{
		ft_strcpy(modifiers->type, "int");
		return (SUCCESS);
	}
	if (*temp == 'f')
	{
		ft_strcpy(modifiers->type, "float");
		return (SUCCESS);
	}
	if (*temp == 's')
	{
		ft_strcpy(modifiers->type, "short");
		return (SUCCESS);
	}
	if (*temp == 'o')
	{
		ft_strcpy(modifiers->type, "OCTAGON");
		return (SUCCESS);
	}
	if (*temp == 'x')
	{
		ft_strcpy(modifiers->type, "hexagon");
		return (SUCCESS);
	}
	if (*temp == 'X')
	{
		ft_strcpy(modifiers->type, "HEXAGON");
		return (SUCCESS);
	}
	return (FAIL);
}

t_flags	*check_for_flags(char *input)
{
	static char	*temp = NULL;
	t_flags		*modifiers;

	if (temp == NULL)
		temp = ft_strchr(input, '%');
	else
		temp = ft_strchr(temp, '%');
	if (!temp)
		return (NULL);
	modifiers = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (!modifiers)
		exit(1);
	temp++;
	temp = check_sign_flag(modifiers, temp);
	temp = check_for_space_flag(modifiers, temp);
	temp = check_for_zero_flag(modifiers, temp);
	temp = check_decimal_flag(modifiers, temp);
	if (check_for_type(modifiers, temp) == FAIL)
		return (NULL);
	return (modifiers);
}

void ft_printf(char *format, ...)
{
	t_flags	*modifiers;
	void	*pointer;
	int		i;

	i = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			ft_putchar(format[i]);
			++i;
		}
		modifiers = check_for_flags(format);
		exit (1);
		if (modifiers != NULL)
			convert_and_print(format, modifiers)
	}	
}

int	main(void)
{
	int	number;

	number = 11;
	ft_printf("this is a text % 823664.98d", number);
	return (0);
}
