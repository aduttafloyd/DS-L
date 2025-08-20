#include <stdio.h>

void swap();

int main(){
    int i, j, r;
    printf("Enter number of rows: ");
    scanf("%d", &r);

    int a[r][3];
    printf("Enter the 3-tuple sparse matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<3;j++){
            scanf("%d", &a[i][j]);
        }
    }

    swap(r, a);
}

void swap(int r, int arr[r][3]){
    int i, j;
    printf("Transpose of the matrix:\n");
    for(i=0;i<r;i++){
        int temp = arr[i][0];
        arr[i][0] = arr[i][1];
        arr[i][1] = temp;
    }

    for(i=0;i<r;i++){
        for(j=0;j<3;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}