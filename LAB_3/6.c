#include <stdio.h>

int countNZ();
void upperT();
void abvBelow();

void main(){
    int i, j, r, c;
    printf("Enter number of row and column of the matrix: ");
    scanf("%d %d", &r, &c);
    int arr[r][c];

    printf("Enter the matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Number of nonzero elements: %d\n", countNZ(r, c, arr));
    printf("Upper triangle:\n");
    upperT(r, c, arr);
    printf("elements just above and just below the main triangle:\n");
    abvBelow(r, c, arr);
}

int countNZ(int r, int c, int arr[r][c]){
    int count=0, i, j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(arr[i][j] != 0){
                count += 1;
            }
        }
    }

    return count;
}

void upperT(int r, int c, int arr[r][c]){
    int i, j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(i < j){
                printf("%d ", arr[i][j]);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void abvBelow(int r, int c, int arr[r][c]){
    int i, j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(i == j-1 || i == j+1){
                printf("%d ", arr[i][j]);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}