#include <stdio.h>

void average(int *a, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }

    int avg=sum/n;
    printf("Mean = %d\n", avg);
}

int main(){
    int i, n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    average(arr, n);

}

