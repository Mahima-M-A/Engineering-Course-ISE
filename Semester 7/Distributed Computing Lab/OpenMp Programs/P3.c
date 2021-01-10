// To implement two separate tasks(multitask): one to generate prime table and other to generate sine table for a given input  using OpenMp.

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void prime_table(int n, int primeTable[])
{
    int i, j, flag;
    int k = 0;
    for(i = 2; k < n; i++)
    {
        flag = 1;
        for (j = 2; j < i; j++)
        {
            if ((i % j) == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            primeTable[k++] = i;
        }
    }
}

void sine_table(int n, double sineTable[])
{
    int i, j;
    double x, pi = 3.1415;
    for (i = 0; i < n; i++)
    {
        sineTable[i] = 0.0;
        for (j = 0; j <= i; j++)
        {
            x = (double)(j)*pi / (double)(n - 1);
            sineTable[i] = sineTable[i] + sin(x);
        }
    }
}

void main() {
    int n, i, j;
    printf("Enter the table size: \n");
    scanf("%d", &n);

    double sineTable[1000];
    int primeTable[1000];

#pragma omp parallel sections
    {
#pragma omp section
        {
            prime_table(n, primeTable);
            printf("\nPrime Table:\n");
            for (i = 0; i < n; i++) {
                printf("%d ", primeTable[i]);
            }
        }
        printf("\n");
#pragma omp section
        {
            sine_table(n, sineTable);
            printf("\nSine Table:\n");
            for (j = 0; j < n; j++) {
                printf("%lf ", sineTable[j]);
            }
        }
    }
}