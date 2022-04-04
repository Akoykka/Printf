/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 08:43:00 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/04 19:23:47 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	char string[] = "kikkeli";
	char string2[] = "muna";
	char a = 'm';
	char b = 'u';
	double f = 123456;

	printf("testing flags:\n\n");
	printf("char a |%c| \n", a);
	//printf("char a |%+c| \n", a);
	printf("char a |%-12c| \n", a);
	//printf("char a |%#c| \n", a);
	//printf("char a |% c| \n", a);
	printf("char a |%12c| \n", a);
	printf("char a |%012c| \n", a);
	//printf("char a |%.1c| \n", a);
	//printf("char a |%llc| \n", a);
	//printf("char a |%hhc| \n", a);
	//printf("char a |%hc| \n", a);

	printf("testing percentage:\n\n");
	printf("percentage twice |%%| \n\n");
	//printf("percentage thrice |%%%| \n\n");
	printf("percentage foursome |%%%%| \n\n");
	printf("percentage twice + space |% %| \n\n");
	printf("percentage twice + zero(10) |%010%| \n\n");
	printf("percentage twice + plus |%+%| \n\n");
	printf("percentage twice - 10 |%-10%| \n\n");
	printf("long int |%Lf| \n\n", f);
}