// Parallel program using OpenMP to sort n element using merge sort

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void merge(int a[], int l, int mid, int r, int b[]) //to sort the elements and simultaneously merge the left and right halves of the array
{
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) //when both the halves contain elements
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid) //when the right half is empty
        b[k++] = a[i++];
    while (j <= r) //when the left half is empty
        b[k++] = a[j++];
    for (int i = l; i <= r; i++) //to copy the sorted elements back into the original array
        a[i] = b[i];
}

void mergeSort(int a[], int l, int r, int temp[])
{
    if (l < r)
    {
        int mid = (l + r) / 2;
#pragma omp parallel sections
        {
#pragma omp section 
            {
                mergeSort(a, l, mid, temp);  //to obtain the left halves of the array
            }
#pragma omp section 
            {
                mergeSort(a, mid + 1, r, temp); //to obtain the right halves of the array
            }
        }
        merge(a, l, mid, r, temp); //to sort and merge
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[50], temp[50];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    mergeSort(a, 0, n - 1, temp);

    printf("\nSorted array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}