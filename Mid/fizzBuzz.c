#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	
	//Divisible by 3 print Fizz
	//Divisible by 5 print Buzz
	//Divisible by 3 and 5 print Fizzbuzz

	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
				printf("FizzBuzz\n");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz\n");
		}
		else if (i % 5 == 0){
			printf("Buzz\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
	return 0;
}