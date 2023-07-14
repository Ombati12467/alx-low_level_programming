#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 * Description: Get the last digit of a number after modulus
 * Return: Always 0
 */
int main(void)
{
	int n;
	int lastnum;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastnum = n % 10;
	if (lastnum > 5)
	{
		printf("The last digit of %d is %d and is greater than 5\n", n, lastnum);
	}
	else if (lastnum == 0)
	{
		printf("The last digit of %d is %d and is 0\n", n, lastnum);
	}
	else
	{
		printf("The last digit of %d is %d and less than 6 and not 0\n", n, lastnum);
	}
	return (0);
}

