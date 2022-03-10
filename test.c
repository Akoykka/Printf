/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:23:37 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/10 09:43:11 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int	i;

	i = 1234;
	printf("int is 1234 % 12.12d\n", i);
//	printf("test %.12 12d", i); NOT VALID
//	printf("test %-.12 12d", i); NOT VALID
	printf("int is 1234 %- 12.12d\n", i);


	printf("int is 1234 %- .d\n", i);

	return (0);
}