/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:06 by akoykka           #+#    #+#             */
/*   Updated: 2022/04/18 19:05:22 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	double number69696 = -56.2012685;
	double number9 = 14.99999000000000037857716961298137903213535;
	
	float ninenine = 99.99999999;
	float negninenine = -99.99999999;
	float ninjaninja = -958.125;
	long double ninjaninja2 = -958.125;
	float ninjaninja22 = 2.50;

	float numero = 2.500000;
	long long numero2 = -9223372036854775807;

	printf("%ld", -9223372036854775807);
	ft_printf("%010lld \n", numero2);
	printf("OGnumber is %.f\n", numero);
	ft_printf("MYnumber is %.f\n", numero);

	float number99 = 12.345678;

	printf("OGnumber is %.2f\n", number99);
	ft_printf("MYnumber is %.2f\n", number99);
	
	ft_printf("%.6f\n", number69696);
	ft_printf("%i\n", (0 / 2));
	ft_printf("%.f\n", ninjaninja22);
	printf("%.0f\n", number99);
	printf("%.1f\n", number99);
	printf("%.f\n", number99);
	printf("%#.f\n", number99);

	ft_printf("%0#10.1Lf\n", ninjaninja2);
	printf("%0#10.1Lf\n", ninjaninja2);
	ft_printf("%.1f\n", number9);
	ft_printf("%d\n", NULL);
	printf("%.f\n", number99);
	printf("thisone with #:%0#10f\n", ninjaninja);
	ft_printf("thisone with #:%0#10f\n", ninjaninja);
	printf("OGnumber +010f is |%+010.f|\n", negninenine);
	ft_printf("MYnumber +010f is |%+010f|\n", negninenine);


	printf("OGnumber 010.2f is |% 010.2f|\n", ninenine);
	ft_printf("MYnumber 010.2f is |% 010.2f|\n", ninenine);

	printf("OGnumber is %lld\n", (long long)number9);
	ft_printf("MYnumber is %lld\n", (long long)number9);

	printf("OGnumber is %f\n", number9);
	ft_printf("MYnumber is %f\n", number9);

	printf("OG. number is %.f\n", number99);
	ft_printf("MY. number is %.f\n", number99);

	printf("OG.1 number is %.1f\n", number99);
	ft_printf("MY.1 number is %.1f\n", number99);

	

	printf("OGnumber is %.3f\n", number99);
	ft_printf("MYnumber is %.3f\n", number99);

	printf("OGnumber is %.4f\n", number99);
	ft_printf("MYnumber is %.4f\n", number99);

	printf("OGnumber is %.5f\n", number99);
	ft_printf("MYnumber is %.5f\n", number99);

	printf("OGnumber is %.10f\n", number99);
	ft_printf("MYnumber is %.10f\n", number99);

	printf("OGnumber is %.11f\n", number99);
	ft_printf("MYnumber is %.11f\n", number99);

	printf("OGnumber is %.20f\n", number99);
	ft_printf("MYnumber is %.20f\n", number99);

	printf("OGnumber is %.40f\n", number99);
	ft_printf("MYnumber is %.40f\n", number99);

	printf("OGnumber is %.40f\n", number99);
	ft_printf("MYnumber is %.40f\n", number99);

	printf("OGnumber is %.40f\n", ninenine);
	ft_printf("MYnumber is %.40f\n", ninenine);

	printf("OGnumber is %+10.39f\n", ninenine);
	ft_printf("MYnumber is %+10.39f\n", ninenine);

	printf("OGnumber is %+10.39f\n", ninenine);
	ft_printf("MYnumber is %+10.39f\n", ninenine);

	printf("OGnumber is %0+10.39f\n", ninenine);
	ft_printf("MYnumber is %0+10.39f\n", ninenine);

	printf("OGnumber 010.f is |%010.f|\n", ninenine);
	ft_printf("MYnumber 010.f is |%010f|\n", ninenine);



	printf("OGnumber 010.2f is |%010.2f|\n", ninenine);
	ft_printf("MYnumber 010.2f is |%010.2f|\n", ninenine);

	printf("OGnumber +010f is |%+010.f|\n", negninenine);
	ft_printf("MYnumber +010f is |%+010f|\n", negninenine);

	int		number;
	int		number2;
	char	str[] = "TESTSTRING";
	number2 = 12;
	number = 111;

	int	i = 1;
	int	j = 12;
	int	k = 123;
	int	l = 1234;
	int	m = 12345;
	int	n = 123456;
	int zero = 0;
	int negative = -1;




	char charry = 120;
	short int shorty = 3333;;
	long int 	longy = -212312333;
	long long int longylongy = 696969696969;


	ft_printf("%.2s is a string", "");
	ft_printf("%.2c", NULL);
	ft_printf("%0+5d", -42);
	ft_printf("%10s is a string", "this");

	printf("#4.3x\n");
	printf("OG: |%#4.3x|\n", number2);
	ft_printf("MY: |%#4.3x|\n\n", number2);

	printf("OG25: |%#25.5x|\n", number2);
	ft_printf("MY25: |%#25.5x|\n", number2);

	printf("OG25: |%#11.4x|\n", number2);
	ft_printf("MY25: |%#11.4x|\n", number2);

	printf("OG25: |%#5.4x|\n", number2);
	ft_printf("MY25: |%#5.4x|\n", number2);

	printf("OG25: |%#5.5x|\n", number2);
	ft_printf("MY25: |%#5.5x|\n", number2);

	printf("OG25: |%#7.15x|\n", number2);
	ft_printf("MY25: |%#7.15x|\n", number2);

	printf("OG25: |%#4.5x|\n", number2);
	ft_printf("MY25: |%#4.5x|\n", number2);

	printf("OG25: |%#1.0x|\n", number2);
	ft_printf("MY25: |%#1.0x|\n", number2);

	printf("OG25: |%#4.11x|\n", number2);
	ft_printf("MY25: |%#4.11x|\n", number2);


	printf("\nhexadecimals \n");
	printf("OG25: |%025x|\n", number);
	ft_printf("MY25: |%025x|\n", number);

	printf("OG25: |%-10x|\n", number2);
	ft_printf("MY25: |%-10x|\n", number2);

	printf("OG25: |%.25x|\n", number);
	ft_printf("MY25: |%.25x|\n", number);

	printf("OG25: |%025x|\n", number2);
	ft_printf("MY25: |%025x|\n", number2);





	printf("\n 111 number  #-5o\n");
	printf("OG -5: |%#-5o|\n", number);
	ft_printf("MY -5: |%#-5o|\n", number);

	printf("\n 111 number #5.7o\n");
	printf("OG -5: |%#5o|\n", number);
	ft_printf("MY -5: |%#5o|\n", number);

	printf("\n 111 number 10.3#o\n");
	printf("OG -5: |%#10.3o|\n", number);
	ft_printf("MY -5: |%#10.3o|\n", number);

	printf("\n 111 number min_width 5o\n");
	printf("OG5: |%5o|\n", number);
	ft_printf("MY5: |%5o|", number);

	printf("\n 111 number min_width 25o\n");
	printf("OG25: |%25o|\n", number);
	ft_printf("MY25: |%25o|\n", number);

	printf("\n 111 number precision .5o\n");
	printf("OG.5: |%.5o|\n", number);
	ft_printf("MY.5: |%.5o|\n", number);

	printf("\n 111 number -5 with .5o\n");
	printf("OG -5.5: |%-5.5o|\n", number);
	ft_printf("MY -5.5: |%-5.5o|\n", number);

	printf("\n 111 number  -5o\n");
	printf("OG -5: |%-5o|\n", number);
	ft_printf("MY -5: |%-5o|\n", number);




	printf("\n\n+ and Zeros (10)\n\n");
	printf("OG|%+010d|\n", i);
	ft_printf("MY|%+010d|\n", i);
	printf("OG|%+010d|\n", j);
	ft_printf("MY|%+010d|\n", j);
	printf("OG|%+010d|\n", k);
	ft_printf("MY|%+010d|\n", k);
	printf("OG|%+010d|\n", l);
	ft_printf("MY|%+010d|\n", l);
	printf("OG|%+010d|\n", m);
	ft_printf("MY|%+010d|\n", m);

	printf("\n\n (10)\n\n");
	printf("OG|%10d|\n", i);
	ft_printf("MY|%10d|\n", i);
	printf("OG|%10d|\n", j);
	ft_printf("MY|%10d|\n", j);
	printf("OG|%10d|\n", k);
	ft_printf("MY|%10d|\n", k);
	printf("OG|%10d|\n", l);
	ft_printf("MY|%10d|\n", l);

	ft_printf("% -1.5d\n", zero);
	ft_printf("MY|%+010ld|\n", longy);

	printf("\n Zero with + sign\n\n");
	printf("%+d\n", zero);

	printf("\n Negative number first with then without + sign\n\n");
	printf("%+d\n", negative);
	printf("%d\n", negative);


	printf("\nPrecision (.10)\n\n");
	printf("OG|%.10d|\n", i);
	ft_printf("MY|%.10d|\n", i);
	printf("OG|%.10d|\n", j);
	ft_printf("MY|%.10d|\n", j);
	printf("OG|%.10d|\n", k);
	ft_printf("MY|%.10d|\n", k);
	printf("OG|%.10d|\n", l);
	ft_printf("MY|%.10d|\n", l);
	printf("OG|%.10d|\n", m);
	ft_printf("MY|%.10d|\n", m);
	printf("OG|%.10d|\n", n);
	ft_printf("MY|%.10d|\n", n);

	printf("\n\nZeros (010)\n\n");
	printf("OG|%010d|\n", i);
	ft_printf("MY|%010d|\n", i);
	printf("OG|%010d|\n", j);
	ft_printf("MY|%010d|\n", j);
	printf("OG|%010d|\n", k);
	ft_printf("MY|%010d|\n", k);
	printf("OG|%010d|\n", l);
	ft_printf("MY|%010d|\n", l);
	printf("OG|%010d|\n", m);
	ft_printf("MY|%010d|\n", m);


	printf("\n\n (10 SHUFFLLE)\n\n");

	ft_printf("MY|%+10d|\n", i);
	printf("OG|%+10d|\n", i);

	printf("OG|%-10d|\n", j);
	ft_printf("MY|%-10d|\n", j);

	printf("OG|% 10d|\n", k);
	ft_printf("MY|% 10d|\n", k);

	printf("OG|%10.6d|\n", l);
	ft_printf("MY|%10.6d|\n", l);


	ft_printf("first number:%d second number:%d\n", number, number2);
	printf("first number:%d second number:%d\n", number, number2);
	ft_printf("MY alternatin numbers %d%d%d%d%d%d%d%d%d\n", number, number2,number, number2, number, number2,number, number2,number);
	printf("OGalternatin numbers %d%d%d%d%d%d%d%d%d\n", number, number2,number, number2, number, number2,number, number2,number);
	printf("\nOG5: 111 number min_width 25o\n");
	printf("OG25: |%25o|\n", number);
	ft_printf("MY25: |%25o|\n", number);

	//ft_printf("MY just integer %d", number);
	printf("OG just integer %d\n", number);
	ft_printf("MY integer with - and .10 %-.10d\n", number);
	printf("OG integer with - and .10 %-.10d\n", number);
	ft_printf("MY integer with + and .10 %+.10d\n", number);
	printf("OG integer with + and .10 %+.10d\n", number);

	ft_printf("first number w flags :%0.9d second number w/o:%d\n", number, number2);
	printf("first number w flags :%.9d second number w/o:%d\n", number, number2);

	//combinations on strings
	ft_printf("MY 10.5: |%10.5s|\n", str);
	printf("OG 10.5: |%10.5s|\n", str);

	//ft_printf("regular: |%s|", str);
	ft_printf("MY.5: |%.5s|\n", str);
	ft_printf("MY25: |%25s|\n", str);
	ft_printf("MY5: |%5s|\n", str);

	printf("OG5: |%5s|\n", str);
	printf("OG25: |%25s|\n", str);
	printf("OG.5: |%.5s|\n", str);
	ft_printf("MY -5.5: |%-5.5s|\n", str);
	printf("OG -5.5: |%-5.5s|\n", str);




	printf("\nhexadecimals \n");
	printf("OG25: |%025x|\n", number);
	ft_printf("MY25: |%025x|\n", number);

	printf("OG25: |%-10x|\n", number2);
	ft_printf("MY25: |%-10x|\n", number2);

	printf("OG25: |%.25x|\n", number);
	ft_printf("MY25: |%.25x|\n", number);

	printf("OG25: |%025x|\n", number2);
	ft_printf("MY25: |%025x|\n", number2);

	printf("\n\n short + and Zeros (10)\n\n");
	printf("OG|%+010hd|\n", shorty);
	ft_printf("MY|%+010hd|\n", shorty);

	printf("\n\n unsigned char + and Zeros (10)\n\n");
	printf("OG|%+010hhd|\n", charry);
	ft_printf("MY|%+010hhd|\n", charry);

	printf("\n\n long + and Zeros (10)\n\n");
	printf("OG|%+010ld|\n", longy);
	ft_printf("MY|%+010ld|\n", longy);

	printf("\n\n long long + and Zeros (10)\n\n");
	printf("OG|%+010lld|\n", longylongy);
	ft_printf("MY|%+010lld|\n", longylongy);

	//printf("OG|%+010lld|\n", m);
	//ft_printf("MY|%+010lld|\n", m);


	float float1;

	float1 = 0.0023456;
	float float2 = 99.9999999;
	void *voidpointer;

	voidpointer = NULL;

	ft_printf("MY float %f\n", float1);
	printf("OG float %f\n", float1);

	ft_printf("MY float %10f\n", float1);
	printf("OG float %10f\n", float1);

	ft_printf("MY float %.5f\n", float1);
	printf("OG float %.5f\n", float1);

	ft_printf("MY float %f\n", float2);
	printf("OG float %f\n", float2);

	ft_printf("MY p float %10p\n", voidpointer);
	printf("OG p float %10p\n", voidpointer);

	float ddd = -0.5500000000;
	ft_printf("MY%.1f\n", ddd);
	printf("OG%.1f\n", ddd);

	ft_printf("MY%.f\n", ddd);
	printf("OG%.f\n", ddd);

	ft_printf("MY%.2f\n", ddd);
	printf("OG%.2f\n", ddd);
	
	
	

	system("leaks ft_printf_test");
	return (0);
}
