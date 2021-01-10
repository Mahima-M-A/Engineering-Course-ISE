// Program to Multiply a matrix by a vector and get the result of the operation using OpenMp.

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, i, j;
    printf("Enter the matrix size(mxn):\n");
    scanf("%d %d", &m, &n);
    int mat[20][20], vec[20], res[20];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat[i][j] = rand() % 100;
        }
        res[i] = 0;
    }
    for (i = 0; i < n; i++)
        vec[i] = rand() % 100;

    printf("Matrix(%dx%d) generated: \n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Vector(%dx1) generated: \n", n);
    for (i = 0; i < n; i++)
        printf("%d\n", vec[i]);

#pragma omp parallel for shared(mat, vec, res) private(i, j)
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            res[i] = res[i] + mat[i][j] * vec[j];

    printf("Result matrix(%dx1) after multiplication\n", m);
    for (i = 0; i < m; i++)
        printf("%d\n", res[i]);
    printf("\n");
    return 0;
}