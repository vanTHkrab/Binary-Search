# include <stdio.h>
# include <stdlib.h>
# include <math.h>


int binary_search(int arr[], int start, int end, int target) {
    int middle = start + ((end - start) / 2 );

    if (arr[middle] == target) {
        return middle;
    }
    if (start <= end){
        if (arr[middle] < target) {
            return binary_search(arr, start = middle + 1, end, target);
        }
        else {
            return binary_search(arr, start, end = middle - 1, target);
        }
    }
    return -1;
}

int main() {
    // int arr[] = {1, 4, 6, 7, 10, 11, 13, 16, 17, 20, 21, 23, 24, 26, 29, 30, 32, 34, 35, 36, 38, 39, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 60, 61, 63, 64, 66, 67, 69, 70, 71, 72};
    int arr[] = {1, 15, 28, 7, 42, 56, 9, 33, 20, 63, 11, 8, 29, 50, 6, 22, 37, 14, 5, 18, 45, 2, 31, 55, 19, 12, 3, 48, 25, 40};
    int end = sizeof(arr) / sizeof(arr[0]);
    int n = end;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                int k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int target = 30;
    int result = binary_search(arr, 0, end - 1, target);
    if (result == -1){
        printf("Element is not present"" in array");
    } 
    else printf("Element is present at ""index %d", result);
    return 0;
}