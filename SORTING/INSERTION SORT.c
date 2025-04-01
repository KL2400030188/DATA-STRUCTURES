#include<stdio.h>
int main()
{
	int n,i,j,temp;
	printf("Enter n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	int a[n];
	for(i=0;i<n;i++)
	{	
	scanf("%d",&a[i]);
    }
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(a[j]>temp&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("Enter sorted list\n");
	for(i=0;i<n;i++)
	{	
	printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}