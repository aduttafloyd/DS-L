#include <stdio.h>

void sparse();

int main(){
    int i, j, r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];
    printf("Enter the matrix: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &a[i][j]);
        }
    }

    int c1 = 0, c2 = 0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j] != 0) c1++;
            else c2++;
        }
    }

    if(c1 < c2) sparse(r, c, a, c1);
    else printf("Number of 0s are less\n");
}

void sparse(int r, int c, int arr[r][c], int count){
    int row=0, ar[count][3], i, j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(arr[i][j] != 0){
                ar[row][0] = i;
                ar[row][1] = j;
                ar[row][2] = arr[i][j];
                row++;
            }
        }
    }

    printf("The sparse matrix: \n");
    printf("R\tC\tValue\n%d\t%d\t%d\n", r, c, count);
    for(i=0;i<row;i++){
        for(j=0;j<3;j++){
            printf("%d\t", ar[i][j]);
        }
        printf("\n");
    }
}