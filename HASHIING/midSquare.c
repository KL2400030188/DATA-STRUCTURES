#include<stdio.h>

int main(){

int n,i,key;

printf("enter the no.of elements:");

scanf("%d",&n);

int a[n];

printf("\n the elements are:");

for(i=0;i<n;i++){

scanf("%d",&a[i]);

}

for(i=0;i<n;i++){

key=a[i]*a[i];

key=key%100;

key=key/10;

printf("The place of %d is %d\n",a[i],key);

}

}
