/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:57:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/12 13:18:59 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int a = 601;

	printf("|%#5.5o|\n", a);



	printf("|%#5.5x|\n", a);
	printf("|%#6.5x|\n", a);
	printf("|%#7.5x|\n", a);
	printf("|%#8.5x|\n", a);
	printf("|%#9.5x|\n\n", a);

	printf("|%#5.5x|\n", a);
	printf("|%#5.6x|\n", a);
	printf("|%#5.7x|\n", a);
	printf("|%#5.8x|\n", a);
	printf("|%#5.9x|\n", a);
	printf("|%#5.10x|\n\n", a);

	printf("|%#-5.5x|\n", a);
	printf("|%#-6.5x|\n", a);
	printf("|%#-7.5x|\n", a);
	printf("|%#-8.5x|\n", a);
	printf("|%#-9.5x|\n", a);
	printf("|%#-10.5x|\n\n", a);

	printf("|%#05x|\n", a);
	printf("|%#06x|\n", a);
	printf("|%#07x|\n", a);
	printf("|%#08x|\n", a);
	printf("|%#09x|\n", a);
	printf("|%#010x|\n", a);
}