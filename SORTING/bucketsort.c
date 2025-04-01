#include <stdio.h>
int getmax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void bucket(int a[], int n) {
    int max = getmax(a, n);
    int bucket[max + 1]; 
    int i, j;

    for (i = 0; i <= max; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        bucket[a[i]]++;
    }

    j = 0;
    for (i = 0; i <= max; i++) {
        while (bucket[i] > 0) {
            a[j++] = i;
            bucket[i]--;
        }
    }
}

void printarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n]; 

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bucket(a, n);

    printf("Sorted array: ");
    printarr(a, n);

    return 0;
}

