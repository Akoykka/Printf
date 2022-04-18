/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:22:43 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 10:30:25 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	float a = 0.05;
	float aa = 0.04;
	float aaa = 0.01;

	float b = 0.005;
	float c = 0.0005;
	float d = 0.15000;
	float e = 10.05;
	float f = 10.005;

	printf("%.1f\n", a);
	printf("%.1f\n", aa);
	printf("%.1f\n", aaa);
	printf("%.1f\n", b);
	printf("%.1f\n\n", c);

	printf("%.1f\n", d);
	printf("%.1f\n", d);
	printf("%.1f\n\n", d);

	printf("%.1f\n", e);
	printf("%.1f\n\n", f);

	printf("%.f\n", a);
	printf("%.f\n", aa);
	printf("%.f\n", aaa);
	printf("%.f\n", b);
	printf("%.f\n", c);
	printf("%.f\n", d);
	printf("%.f\n", e);
	printf("%.f\n\n", f);

	printf("%.2f\n", a);
	printf("%.2f\n", aa);
	printf("%.2f\n", aaa);
	printf("%.2f\n", b);
	printf("%.2f\n", c);
	printf("%.2f\n", d);
	printf("%.2f\n", e);
	printf("%.2f\n\n", f);





}