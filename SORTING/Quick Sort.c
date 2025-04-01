#include <stdio.h>
void quick_sort(int a[100], int left, int right);
int main() 
{
    int a[100], n, i;
    printf("Enter No.of elements");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    printf("The sorted list is: ");
    {
    	for(i=0;i<n;i++)
    	{
    		printf("%d\t",a[i]);
		}
	}
    return 0;
}
void quick_sort(int a[100], int left, int right) 
{
    int i, j, pivot, temp;

    if (left < right) 
	{
        i = left;
        j = right;
        pivot = left;

        while (i < j) 
		{
            while (a[i] <= a[pivot] && i < right) 
			{
                i++;
            }
            while (a[j] > a[pivot]) 
			{
                j--;
            }
            if (i < j) 
			{
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        quick_sort(a, left, j - 1);
        quick_sort(a, j + 1, right);
    }
}

