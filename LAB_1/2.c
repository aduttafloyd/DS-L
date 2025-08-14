#include <stdio.h>
#include <stdlib.h>

void average(int *ptr, int n);
void sl(int *ptr, int n);
void insert(int **ptr, int *n, int num, int p);
void delete(int **ptr, int *n, int p);
void display(int *ptr, int n);

int main() {
    int i, n, ch;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *ptr = (int*)malloc(sizeof(int) * n);

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    do {
        printf("\n1. Find mean\n2. Find 2nd largest\n3. Insert a number\n4. Delete a number\n5. Display array\n0. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            average(ptr, n);
        }
        else if (ch == 2) {
            sl(ptr, n);
        }
        else if (ch == 3) {
            int num, p;
            printf("Enter number and position to insert (0 to %d): ", n);
            scanf("%d %d", &num, &p);
            if (p >= 0 && p <= n) {
                insert(&ptr, &n, num, p);
            } else {
                printf("Invalid position!\n");
            }
        }
        else if (ch == 4) {
            int p;
            printf("Enter position to delete (0 to %d): ", n-1);
            scanf("%d", &p);
            if (p >= 0 && p < n) {
                delete(&ptr, &n, p);
            } else {
                printf("Invalid position!\n");
            }
        }
        else if (ch == 5) {
            display(ptr, n);
        }
    } while (ch != 0);

    free(ptr);
    return 0;
}

void average(int *ptr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ptr[i];
    }
    float mean = (float)sum / n;
    printf("Mean = %.2f\n", mean);
}

void sl(int *ptr, int n) {
    if (n < 2) {
        printf("Not enough elements for second largest!\n");
        return;
    }
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ptr[j + 1] > ptr[j]) {
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
    printf("Second Largest = %d\n", ptr[1]);
}

void insert(int **ptr, int *n, int num, int p) {
    *ptr = (int*)realloc(*ptr, (*n + 1) * sizeof(int));
    if (*ptr == NULL) {
        printf("Memory reallocation failed!\n");
        return;
    }
    for (int i = *n; i > p; i--) {
        (*ptr)[i] = (*ptr)[i - 1];
    }
    (*ptr)[p] = num;
    (*n)++;
    printf("Number inserted successfully. New size: %d\n", *n);
}

void delete(int **ptr, int *n, int p) {
    for (int i = p; i < *n - 1; i++) {
        (*ptr)[i] = (*ptr)[i + 1];
    }
    *ptr = (int*)realloc(*ptr, (*n - 1) * sizeof(int));
    if (*ptr == NULL && *n > 1) {
        printf("Memory reallocation failed!\n");
        return;
    }
    (*n)--;
    printf("Number deleted successfully. New size: %d\n", *n);
}

void display(int *ptr, int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}