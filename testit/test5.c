/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:37:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/16 19:18:06 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

///// OCTAL TESTING GROUND

int main(void)
{
	int number = -1;
	int number2 = -10;
	int number3 = 0;
	int number4 = 23;
	int number5 = 500;
	int number6 = 550;
	int number7 = 23444;
	int number8 = 100000;

	unsigned long number9 = 666;
	unsigned long number10 = 1039999999;
	unsigned long number11 = 12345667890;
	unsigned long number12 = 23454577686786;

	long long number13 = 234234234234324;
	long long number14 = -234234234234;
	long long number15 = -234234223333;
	long long number16 = -2349847598374;

	printf("testing flags:\n\n");
	printf("number is %o \n", number);
	printf("number2 is %o \n", number2);
	printf("number3 is %o \n", number3);
	printf("number4 (23) is %o \n", number4);

	//precision flag
	printf("number5 (500).20 is |%.20o| \n", number5);
	printf("number5 (500).10 is |%.10o| \n", number5);
	printf("number5 (500).5 is |%.5o| \n", number5);
	printf("number5 (500).4 is |%.4o| \n", number5);
	printf("number5 (500).3 is |%.3o| \n", number5);
	printf("number5 (500).2 is |%.2o| \n", number5);
	printf("number5 (500). is |%.o| \n", number5);

	// # number tracking
	printf("number5 (500)20 is |%20o| \n", number5);
	printf("number5 (500)10 is |%10o| \n", number5);
	printf("number5 (500)5 is |%5o| \n", number5);
	printf("number5 (500)4 is |%4o| \n", number5);
	printf("number5 (500)3 is |%3o| \n", number5);
	printf("number5 (500)2 is |%2o| \n", number5);
	printf("number5 (500)1 is |%1o| \n", number5);
	printf("number5 (500)0 is |%0o| \n", number5);



	/// 0 flag
	printf("number5 (500)020 is |%020o| \n", number5);
	printf("number5 (500)010 is |%010o| \n", number5);
	printf("number5 (500)05 is |%05o| \n", number5);
	printf("number5 (500)04 is |%04o| \n", number5);
	printf("number5 (500)03 is |%03o| \n", number5);
	printf("number5 (500)02 is |%02o| \n", number5);
	printf("number5 (500)01 is |%01o| \n", number5);
	printf("number5 (500)0 is |%0o| \n", number5);

	/// minus flag
	printf("number5 (500)-20 is |%-20o| \n", number5);
	printf("number5 (500)-10 is |%-10o| \n", number5);
	printf("number5 (500)-5 is |%-5o| \n", number5);
	printf("number5 (500)-4 is |%-4o| \n", number5);
	printf("number5 (500)-3 is |%-3o| \n", number5);
	printf("number5 (500)-2 is |%-2o| \n", number5);
	printf("number5 (500)-1 is |%-1o| \n", number5);
	printf("number5 (500)-1 is |%-o| \n", number5);

	// space flag
	printf("space flag is not valid\n");
	//printf("number5 (500) is % 20o \n", number5);

	/// + flag
	printf("+ flag is not valid\n");
	//printf("number5 (500)+ is %+o \n", number5);

	printf("\nPRECISION with Zeroflag\n");
	printf("number5 010.10o is |%010.10o| \n", number5);

	printf("\nMINUS WITH 0 flag\n");
	printf("number5 -07o is |%-07o| \n\n", number5);
	
	return (0);
}



//if precision then no zero flag 

//	if minus flag no zero flag

// if plus no space flag