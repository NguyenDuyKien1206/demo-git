#include <iostream>
using namespace std;


void buildHeap(int *A, int n, int i) {
    int e = A[i];
    int j = 2 * i + 1; 

    while (j < n) {
        int k = j + 1; 
        if (k < n && A[j] < A[k]) 
            j = k; 

        if (A[j] <= e) break; 

        A[i] = A[j]; 
        i = j;        
        j = 2 * i + 1;
    }

    A[i] = e; 
}


void heapSort(int *A, int n) {
    for (int i = n/2 - 1; i >= 0; i--) 
        buildHeap(A, n, i);

    while (n > 1) {
        swap(A[0], A[n - 1]);
        n--;
        buildHeap(A, n, 0);
    }
}

int main() {
    int A[] = {33, 44, 11, 66, 55, 22};
    int n = sizeof(A) / sizeof(A[0]);

    heapSort(A, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}


