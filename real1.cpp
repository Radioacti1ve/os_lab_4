#include "func.hpp"
#include <iostream>
extern "C" {
int gcf(int A, int B) {
    int result;
    if(B != 0) {
        result = gcf(B, A % B);
    } else {
        result = A;
    }
    return result;
}

int *sort(int *array, int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = true;
            }
        }
    } while (swapped);

    return array;
}
}