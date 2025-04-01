#include<stdio.h>
int main()
{
int M;
printf("Enter Size of table:\n");
scanf("%d",&M);
int a[M],i;
for(i=0;i<M;i++)
{
a[i]=-1;
}
int n,keys,x;
printf("Enter num of keys:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&keys);
x=keys%M;
if(a[x]==-1)
{
a[x]=keys;
}
else
{
printf("Collision occurred\n");
}
}
for(i=0;i<M;i++)
{
printf("%3d",a[i]);
}
}

// another method
(or)

#include <stdio.h>
int main() {
int n, i;
printf("Enter size of the hash table: ");
    scanf("%d", &n);
    int key[5], index[n]; // Change the size of index array to n
    printf("Enter 5 keys: "); // Prompt user to enter only 5 keys
    for (i = 0; i < 5; i++)  
        scanf("%d", &key[i]);      

    for (i = 0; i < n; i++) {  
        index[i] = 0; // Initialize all indexes to 0
    }

    for (i = 0; i < 5; i++) {  
        index[key[i] % n] = key[i]; // Set index value to key
    }  

    printf("\nThe indexes of the values in the Hash Table: \n");  
    for (i = 0; i < n; i++) {  
        printf("Index %d: %d\n", i, index[i]);  
    }  

    return 0;  
}
