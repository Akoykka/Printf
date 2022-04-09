/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:13:37 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/15 18:24:48 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char string[] = "kikkeli";
	char string2[] = "muna";


	printf("\n flags w string\n");
	printf("\n + flag\n");
	//printf("testphrase kikkeli : |%+s|\n", string);
	//printf("testphrase muna : |%+s|\n", string2);
	printf("+flag is not allowed \n");

	printf("\n flag space (10)  not allowed\n");
	//printf("testphrase kikkeli : |% 10s|\n", string);
	//printf("testphrase muna : |% 10s|\n", string2);


	printf("\n Minus flag (10)\n");
	printf("testphrase kikkeli : |%-10s|\n", string);
	printf("testphrase muna : |%-10s|\n", string2);
	printf("prints max 10 fill with spaces in the end \n");

	printf("\n Minus flag (5)\n");
	printf("testphrase kikkeli : |%-5s|\n", string);
	printf("testphrase muna : |%-5s|\n", string2);
	//printf("prints max 10 fill with spaces in the end \n");


	printf("\n Minus flag (10)+ .10\n");
	printf("testphrase kikkeli : |%-10.10s|\n", string);
	printf("testphrase muna : |%-10.10s|\n", string2);
	printf("prints max 10 minus overrides precision (.10) \n");

	printf("\n flag .10 w string\n");
	printf("testphrase kikkeli : |%.10s|\n", string);
	printf("testphrase muna : |%.10s|\n", string2);

	printf("\n flag .5 \n");
	printf("testphrase kikkeli : |%.5s|\n", string);
	printf("testphrase muna : |%.5s|\n", string2);
	printf("enintaan 5 ja ei tayteta\n");

	printf("\n flag number (5) \n");
	printf("testphrase kikkeli : |%5s|\n", string);
	printf("testphrase muna : |%5s|\n", string2);
	printf("minimissaan 5 ja taytetaan alkuun\n");

	printf("\n flag number (10) \n");
	printf("testphrase kikkeli : |%10s|\n", string);
	printf("testphrase muna : |%10s|\n", string2);
	printf("minimissaan 10 ja taytetaan alkuun\n");

	printf("\n flag number -10(10) \n");
	//printf("testphrase kikkeli : |%-1010s|\n", string);
	//printf("testphrase muna : |%-1010s|\n", string2);
	printf("just number ei voi olla kuin ekana lasketaan minusflagiksi\n");

	printf("\n flag number (10) ja .5 \n");
	printf("testphrase kikkeli : |%10.5s|\n", string);
	printf("testphrase muna : |%10.5s|\n", string2);
	printf("minimissaan 10 ja taytetaan alkuun\n");

	printf("\n flag number (10) ja .10 \n");
	printf("testphrase kikkeli : |%10.10s|\n", string);
	printf("testphrase muna : |%10.10s|\n", string2);
	
	printf("minimissaan 10 ja taytetaan alkuun\n");

	printf("\n flag number -10 ja .5 \n");
	printf("testphrase kikkeli : |%-10.5s|\n", string);
	printf("testphrase muna : |%-10.5s|\n", string2);
	//printf("minimissaan 10 ja taytetaan alkuun\n");


}