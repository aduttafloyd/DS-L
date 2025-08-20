#include <stdio.h>

#define MAX_TERMS 100

void add(int r1, int r2, int m1[][3], int m2[][3]) {
    int result[MAX_TERMS][3];
    int num_terms_result = 0;
    int i = 0, j = 0, k = 0;
    
    while (i < r1 && j < r2) {
        if (k >= MAX_TERMS) {
            printf("Result matrix exceeds maximum terms!\n");
            return;
        }
        
        if (m1[i][0] < m2[j][0] || (m1[i][0] == m2[j][0] && m1[i][1] < m2[j][1])) {
            result[k][0] = m1[i][0];
            result[k][1] = m1[i][1];
            result[k][2] = m1[i][2];
            i++;
            k++;
        } else if (m1[i][0] > m2[j][0] || (m1[i][0] == m2[j][0] && m1[i][1] > m2[j][1])) {
            result[k][0] = m2[j][0];
            result[k][1] = m2[j][1];
            result[k][2] = m2[j][2];
            j++;
            k++;
        } else {
            result[k][0] = m1[i][0];
            result[k][1] = m1[i][1];
            result[k][2] = m1[i][2] + m2[j][2];
            if (result[k][2] != 0)
                k++;
            i++;
            j++;
        }
    }
    
    while (i < r1) {
        if (k >= MAX_TERMS) {
            printf("Result matrix exceeds maximum terms!\n");
            return;
        }
        result[k][0] = m1[i][0];
        result[k][1] = m1[i][1];
        result[k][2] = m1[i][2];
        i++;
        k++;
    }
    
    while (j < r2) {
        if (k >= MAX_TERMS) {
            printf("Result matrix exceeds maximum terms!\n");
            return;
        }
        result[k][0] = m2[j][0];
        result[k][1] = m2[j][1];
        result[k][2] = m2[j][2];
        j++;
        k++;
    }
    
    num_terms_result = k;
    
    printf("\nResult matrix (sum):\n");
    for (i = 0; i < num_terms_result; i++) {
        printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
    }
}

void main() {
    int r1, r2, i, j;
    printf("enter number of rows in the sparse matrix 1: ");
    scanf("%d", &r1);
    int m1[r1][3];
    printf("Enter sparse matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("enter number of rows in the sparse matrix 2: ");
    scanf("%d", &r2);
    int m2[r2][3];
    printf("Enter sparse matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    add(r1, r2, m1, m2);
}