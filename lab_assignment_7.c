#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void bubbleSort(int arr[], int size, int swapCount[]) {

    int i, j, temp;


    for (i = 0; i < size -1; i++) {
        for (j = 0; j < size - i -1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount[arr[j]]++;
                swapCount[arr[j + 1]]++;
                
            }

        }
    }
    
}

void selectSort(int arr[], int size, int swapCount[]) {
    int i, j, minIdx, temp;
    for (i = 0; i < size - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            
            swapCount[arr[minIdx]]++;
            swapCount[arr[i]]++;

            
            temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}


void printSwapCounts(int arr[], int size, int swapCount[]) {
    for (int i = 0; i < size; i++) {
        printf("%d is swapped %d time(s)\n", arr[i], swapCount[arr[i]]);
    }
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void resetSwapCount(int swapCount[]) {
    for (int i = 0; i <= MAX; i++) {
        swapCount[i] = 0;
    }
}

int main() {

    int originalArr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr1[sizeof(originalArr1) / sizeof(originalArr1[0])];
    int swapCount[MAX + 1] = {0};

    int originalArr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arr2[sizeof(originalArr2) / sizeof(originalArr2[0])];
    int swapCount2[MAX + 1] = {0};

    copyArray(originalArr1, arr1, sizeof(arr1) / sizeof(arr1[0]));
    copyArray(originalArr2, arr2, sizeof(arr2) / sizeof(arr2[0]));

    printf("\narray 1 bubble sort:\n");
    bubbleSort(arr1, sizeof(arr1) / sizeof(arr1[0]), swapCount);
    printSwapCounts(arr1, sizeof(arr1) / sizeof(arr1[0]), swapCount);
    resetSwapCount(swapCount); 
    copyArray(originalArr1, arr1, sizeof(arr1) / sizeof(arr1[0])); 

    printf("\narray 1 select sort:\n");
    selectSort(arr1, sizeof(arr1) / sizeof(arr1[0]), swapCount);
    printSwapCounts(arr1, sizeof(arr1) / sizeof(arr1[0]), swapCount);

    printf("\narray 2 bubble sort:\n");
    bubbleSort(arr2, sizeof(arr2) / sizeof(arr2[0]), swapCount2);
    printSwapCounts(arr2, sizeof(arr2) / sizeof(arr2[0]), swapCount2);
    resetSwapCount(swapCount2); 
    copyArray(originalArr2, arr2, sizeof(arr2) / sizeof(arr2[0])); 

    printf("\narray 2 select sort:\n");
    selectSort(arr2, sizeof(arr2) / sizeof(arr2[0]), swapCount2);
    printSwapCounts(arr2, sizeof(arr2) / sizeof(arr2[0]), swapCount2);

    return 0;  
}