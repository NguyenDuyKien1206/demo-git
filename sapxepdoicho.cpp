#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exchangeSort(int a[], int n) {
    int i, j;
    for (int i = 0; i<n - 2; i++){
        for (int j = n - 1; j>i; j--){
            if (a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
            }
        }
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
    exchangeSort(arr, n);
    printArray(arr, n);
    return 0;
}
