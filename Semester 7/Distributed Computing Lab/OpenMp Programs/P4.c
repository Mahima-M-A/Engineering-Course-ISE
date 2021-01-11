// Program to show how first private clause works. (Factorial program)

#include<omp.h>
#include<stdio.h>

void main()
{
	int fact1 = 1, fact2 = 1;
	int n, i;

	printf("Enter a number:\n");
	scanf("%d", &n);

#pragma omp parallel for num_threads(4)
	for (i = 2; i <= n; i++)
	{
		fact1 *= i;
	}

	printf("When firstprivate is not used\n");
	printf("Factorial of %d is %d \n", n, fact1);

#pragma omp parallel for firstprivate(fact2) num_threads(4)
	for (i = 2; i <= n; i++)
	{
		fact2 *= i;
	}

	printf("When first private is used\n");
	printf("factorial of %d is %d \n", n, fact2);
}
