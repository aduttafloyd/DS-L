#include <stdio.h>
#define max_size 50
#define max_nonzero 50

typedef struct{
    int row, col, value;
}Tuple;

void toSparse();
void toDisplay();

void main() {
    int arr[max_size][max_size], i, j, r, c;
    Tuple sparse[max_nonzero];
    int size;
    
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter the matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    toSparse(arr, r, c, sparse, &size);
    toDisplay(sparse, size);
}

void toSparse(int a[max_size][max_size], int r, int c, Tuple sparse[], int* size){
    int i, j;
    *size = 1;
    sparse[0].row = r;
    sparse[0].col = c;
    sparse[0].value = 0;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j] != 0){
                sparse[*size].row = i;
                sparse[*size].col = j;
                sparse[*size].value = a[i][j];
                (*size)++;
                sparse[0].value++;
            }
        }
    }
}

void toDisplay(Tuple sparse[], int size){
    int i;
    printf("the 3-tuple sparse matrix:\n");
    for(i=0;i<size;i++){
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}