#include<stdio.h>
int main()
{
	int n,i,j,temp,gap;
	printf("Enter n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	int a[n];
	for(i=0;i<n;i++)
	{	
	scanf("%d",&a[i]);
    }
    for (gap = n / 2; gap >= 1; gap = gap / 2) 
	{
        for (j = gap; j < n; j++) 
		{
            for (i = j - gap; i >= 0; i -= gap) 
			{
                if (a[i + gap] >= a[i]) 
				{
                    break;
                } 
				 else 
				{
                    temp = a[i + gap];
                    a[i + gap] = a[i];
                    a[i] = temp;
                }
            }
        }
    }

    for (i = 0; i < n; i++) 
	{
        printf("%d\t", a[i]);
    }

    return 0;
}