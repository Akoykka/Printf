/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:09:52 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/14 14:53:54 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	i = 1;
	int	j = 12;
	int	k = 123;
	int	l = 1234;
	int	m = 12345;
	int	n = 123456;


	printf("\nDecimals (10)\n\n");
	printf("%.10d\n", i);
	printf("%.10d\n", j);
	printf("%.10d\n", k);
	printf("%.10d\n", l);
	printf("%.10d\n", m);
	printf("%.10d\n", n);

	printf("\n\nZeros (10)\n\n");
	printf("%010d\n", i);
	printf("%010d\n", j);
	printf("%010d\n", k);
	printf("%010d\n", l);
	printf("%010d\n", m);
	printf("%010d\n", n);

	printf("\n\nMinus (10)\n\n");
	printf("%-10d\n", i);
	printf("%-10d\n", j);
	printf("%-10d\n", k);
	printf("%-10d\n", l);
	printf("%-10d\n", m);
	printf("%-10d\n", n);

	printf("\n\nplus (10)\n\n");
	printf("%+10d\n", i);
	printf("%+10d\n", j);
	printf("%+10d\n", k);
	printf("%+10d\n", l);
	printf("%+10d\n", m);
	printf("%+10.6d\n", n);

	printf("\n\n (10)\n\n");
	printf("%10d\n", i);
	printf("%10d\n", j);
	printf("%10d\n", k);
	printf("%10d\n", l);
	printf("%10d\n", m);
	printf("%10.6d\n", n);

	return (0);
}
