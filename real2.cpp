#include "func.hpp"
extern "C" {
int gcf(int A, int B) {
    int res = 1;
    int k;
    if( A <= B) {
        k = A;
    } else {
        k = B;
    }
    for(int i = 2; i < k; ++i) {
        if(A % i == 0 and B % i == 0) {
            return i;
        }
    }
}


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *array, int low, int high) {
    int pivot = array[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && array[left] < pivot) {
            ++left;
        }

        while (right >= left && array[right] > pivot) {
            --right;
        }

        if (left <= right) {
            swap(array[left], array[right]);
        } else {
            break;
        }
    }

    swap(array[low], array[right]);
    return right;
}

void quicksort(int *array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

int *sort(int *array, int size) {
    quicksort(array, 0, size - 1);
    return array;
}
}