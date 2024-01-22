#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void reverseArray(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

void randomizeArray(int arr[], int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


int main() {
    int length;
    printf("Enter the length:\n");
    if (scanf("%d", &length) != 1 || length <= 0) {
        printf("Invalid input for length. Please enter a positive integer.\n");
        return 1; // Return an error code
    }

    int arr[length]; // Declare an array of the specified length

    printf("Enter %d numbers (space separated):\n", length);
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for array element %d. Please enter an integer.\n", i + 1);
            return 1; // Return an error code
        }
    }

    while (1) {
        printf("Choose an operation:\n");
        printf("(0) : exit\n");
        printf("(1) : reverse array\n");
        printf("(2) : randomize array\n");
        printf("(3) : sort array\n");

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid option.\n");
            return 1; // Return an error code
        }

        switch (choice) {
            case 0:
                return 0;
            case 1:
                reverseArray(arr, length);
                printf("[ ");
                
                for (int i = 0; i < length; i++) {
                     printf("%d ", arr[i]);
                }
                printf("]\n");

                break;
            case 2:
                randomizeArray(arr, length);

                printf("[ ");
                for (int i = 0; i < length; i++) {
                    printf("%d ", arr[i]);
                }
                printf("]\n");

                break;
            case 3:
                sortArray(arr, length);

                printf("[ ");
                for (int i = 0; i < length; i++) {
                    printf("%d ", arr[i]);
                }
                printf("]\n");
                
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}