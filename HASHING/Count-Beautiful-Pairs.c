//3.Count Beautiful Pairs 
//You have an array A of N integers. A pair of indices (i,j) is called Beautiful if Ai=Aj2 and 1≤i<j≤N 
//Count the number of Beautiful Pairs in the given array. 
//Task 
//Try to solve this problem in N2 time complexity. 

#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (a[i] == a[j] * a[j]) 
            {
                res += 1;
            }
        }
    }

    printf("%d", res);

    return 0;
}

