/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfloat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:18:07 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/06 13:03:31 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	double number = 34.125;
	float number1 = 12.345678;

	printf("number is %lld\n", (long long)number);
	printf("number is %f\n", number1);
	printf(". number is %.f\n", number1);
	printf(".1 number is %.1f\n", number1);
	printf("number is %.2f\n", number1);
	printf("number is %.3f\n", number1);
	printf("number is %.4f\n", number1);
	printf("number is %.5f\n", number1);
	printf("number is %.10f\n", number1);
	printf("number is %.11f\n", number1);
	printf("number is %.20f\n", number1);
	printf("number is %.40f\n", number1);
}