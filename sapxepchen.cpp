#include <iostream>
using namespace std;

void insertionSort(int A[], int n) {
     for (int i = 1; i < n; i++) {
           int x = A[i];
           int j = i;
           while (j > 0 && A[j - 1] > x) {
            A[j] = A[j - 1];
             j--;
            }
            A[j] = x;
      }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main () {
    int arr[] = {3, 10, 1, 23, 103, 34, 17, 53, 64, 71};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
