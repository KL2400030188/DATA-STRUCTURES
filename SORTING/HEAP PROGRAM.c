// Heap Sort
#include <stdio.h>  
void heapify(int a[], int n, int i)  
{  
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
    
    if (left < n && a[left] > a[largest])  
        largest = left;  
    
    if (right < n && a[right] > a[largest])  
        largest = right;  
    
    if (largest != i) {  
    
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  

void heapSort(int a[], int n)  
{  
	int i;
    for (i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  

    for (i = n - 1; i >= 0; i--) {  


        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  

void printArr(int arr[], int n)  
{  
	int i;
    for (i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }  
          
}  
int main()  
{  
    int a[20] ,size,i;
    printf("\nEnter Size of the Array : ");
    scanf("%d",&size);
    
    printf("\nEnter Elements for array :\n");
    for(i=0;i<size;i++){
    	scanf("%d",&a[i]);
	}
 
    printf("Before sorting array elements are - \n");  
    printArr(a,size);  
    heapSort(a, size);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a,size);  
    return 0;  
}