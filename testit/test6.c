#include <stdio.h>

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
	printf("number is %x \n", number);
	printf("number2 is %x \n", number2);
	printf("number3 is %x \n", number3);
	printf("number4 (23) is %x \n", number4);

	//precisixn flag
	printf("number5 (500).20 is |%.20x| \n", number5);
	printf("number5 (500).10 is |%.10x| \n", number5);
	printf("number5 (500).5 is |%.5x| \n", number5);
	printf("number5 (500).4 is |%.4x| \n", number5);
	printf("number5 (500).3 is |%.3x| \n", number5);
	printf("number5 (500).2 is |%.2x| \n", number5);
	printf("number5 (500). is |%.x| \n", number5);

	// # number tracking
	printf("number5 (500)20 is |%20x| \n", number5);
	printf("number5 (500)10 is |%10x| \n", number5);
	printf("number5 (500)5 is |%5x| \n", number5);
	printf("number5 (500)4 is |%4x| \n", number5);
	printf("number5 (500)3 is |%3x| \n", number5);
	printf("number5 (500)2 is |%2x| \n", number5);
	printf("number5 (500)1 is |%1x| \n", number5);
	printf("number5 (500)0 is |%0x| \n", number5);



	/// 0 flag
	printf("number5 (500)020 is |%020x| \n", number5);
	printf("number5 (500)010 is |%010x| \n", number5);
	printf("number5 (500)05 is |%05x| \n", number5);
	printf("number5 (500)04 is |%04x| \n", number5);
	printf("number5 (500)03 is |%03x| \n", number5);
	printf("number5 (500)02 is |%02x| \n", number5);
	printf("number5 (500)01 is |%01x| \n", number5);
	printf("number5 (500)0 is |%0x| \n", number5);

	/// minus flag
	printf("number5 (500)-20 is |%-20x| \n", number5);
	printf("number5 (500)-10 is |%-10x| \n", number5);
	printf("number5 (500)-5 is |%-5x| \n", number5);
	printf("number5 (500)-4 is |%-4x| \n", number5);
	printf("number5 (500)-3 is |%-3x| \n", number5);
	printf("number5 (500)-2 is |%-2x| \n", number5);
	printf("number5 (500)-1 is |%-1x| \n", number5);
	printf("number5 (500)-1 is |%-x| \n", number5);

	// space flag
	printf("space flag is nxt valid\n");
	//printf("number5 (500) is % 20x \n", number5);

	/// + flag
	printf("+ flag is nxt valid\n");
	//printf("number5 (500)+ is %+x \n", number5);

	printf("\nPRECISIoN with Zeroflag\n");
	printf("number5 010.10x is |%010.10x| \n", number5);

	printf("\nMINUS WITH 0 flag 0 is ignored\n");
	 // printf("number5 -07x is |%-07x| \n\n", number5);


	printf("\nPRECISIoN with MINUS FLAG\n");
	printf("number5 (500)-5.5 is |%-5.5x| \n", number5);
	printf("number5 (500)-10.5 is |%-10.5x| \n", number5);
	printf("number5 (500)-5.10 is |%-5.10x| \n", number5);
	printf("number5 (500)-10.10 is |%-10.10x| \n", number5);

	printf("\nSHORTLONGLONGETC\n");
	printf("number5 (234234234234324)with ll is |%llx| \n", number13);	
	printf("number5 (234234234234324)with l is |%lx| \n", number9);
	printf("number5 (500)with hh is |%hhx| \n", number5);	
	printf("number5 (500)with h is |%hx| \n", number5);


	printf()
	return (0);
}

// Flag 0 is ignore when flag - is present