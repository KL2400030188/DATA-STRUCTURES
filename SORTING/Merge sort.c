#include <stdio.h>
#define MAX 100
void Merge(int a[], int b[], int lb, int mid, int ub) 
{
    int i = lb;       
    int j = mid + 1;  
    int k = lb;       

    while (i <= mid && j <= ub) 
	{
        if (a[i] <= a[j]) 
		{
            b[k] = a[i];
            i++;
        } 
		else 
		{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid) 
	{
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= ub) 
	{
        b[k] = a[j];
        j++;
        k++;
    }
    for (k = lb; k <= ub; k++) 
	{
        a[k] = b[k];
    }
}
void MergeSort(int a[], int b[], int lb, int ub) 
{
    if (lb < ub) 
	{
        int mid = (lb + ub) / 2;

        MergeSort(a, b, lb, mid);
        
        MergeSort(a, b, mid + 1, ub);

        Merge(a, b, lb, mid, ub);
    }
}
int main() 
{
    int n, i;
    int a[MAX], b[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    MergeSort(a, b, 0, n - 1);
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
