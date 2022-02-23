#include <iostream>
#include "arrays.h"

using namespace std;

void quickSort(int* array, int low, int high) {

    int i = low;
    int j = high-1;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j) {

        while (array[i] < pivot)
            i++;

        while (array[j] > pivot)
            j--;

        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }

    }

    if (j > low)
        quickSort(array, low, j);

    if (i < high)
        quickSort(array, i, high);

}

void heapify(int arr[], int n, int root) {

    int largest = root; 
    int l = 2 * root + 1; 
    int r = 2 * root + 2;

    if (l < n && arr[l] < arr[largest])
        largest = l;

    if (r < n && arr[r] < arr[largest])
        largest = r;

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}

int main() {

    int n;
    cin >> n;
    int** mass = create(n, n);
    read(mass, n, n);
    cout << endl;
    print(mass, n, n);
    cout << endl;

    for (int z = 1; z < n - 1; z++) {

        int* dopmass = create(n - z);

        for (int i = 0; i < n - z; i++)
            dopmass[i] = mass[i][i + z];

        quickSort(dopmass, 0, n - z);

        for (int i = 0; i < n - z; i++)
            mass[i][i + z] = dopmass[i];

        deleted(dopmass, n-z);

    }

    for (int z = 1; z < n - 1; z++) {

        int* dopmass = create(n - z);

        for (int i = 0; i < n - z; i++)
            dopmass[i] = mass[i + z][i];

        heapSort(dopmass, n - z);

        for (int i = 0; i < n - z; i++)
            mass[i + z][i] = dopmass[i];

        deleted(dopmass, n-z);

    }

    print(mass, n, n);

}

/*

ввод

5
25 24 23 22 21
2 19 18 17 16
3 8 13 12 11
4 9 14 7 6
5 10 15 20 1

вывод

25      6       11      16      21
20      19      12      17      22
15      14      13      18      23
10      9       8       7       24
5       4       3       2       1

*/