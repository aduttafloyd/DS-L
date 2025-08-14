#include <stdio.h>
#include <stdlib.h>

void secondLargest();

void main() {
    int i, n;
    printf("enter size of array: ");
    scanf("%d", &n);

    int *ptr = (int*) malloc(n * sizeof(int));
    printf("Enter the array: ");
    for(i=0;i<n;i++){
        scanf("%d", ptr+i);
    }

    secondLargest(ptr, n);
}

void secondLargest(int *ptr, int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(ptr[j] < ptr[j+1]){
                int temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%d ", *(ptr+i));
    }
}