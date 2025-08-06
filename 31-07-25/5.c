#include <stdio.h>
#include <stdlib.h>

void rotateArray(int *arr, int n, int pos) {
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    int index = 0;
    for (int i = pos + 1; i < n; i++) {
        temp[index++] = arr[i];
    }
    for (int i = 0; i <= pos; i++) {
        temp[index++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}

int searchElement(int *arr, int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, element;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &element);
    int pos = searchElement(arr, n, element);
    if (pos == -1) {
        printf("Element %d not found in the array!\n", element);
    } else {
        rotateArray(arr, n, pos);
        printf("Rotated array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}