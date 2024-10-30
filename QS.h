#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // Find the middle index
    int middle = (left + right) / 2;

    // Sorts values at those 3 indices
    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }
    if (array[middle] > array[right]) {
        std::swap(array[middle], array[right]);
    }
    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }
    
    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // Call medianOfThree to find the middle
    int pivotInd = medianOfThree(array, left, right);
    T pivotVal = array[pivotInd];

    // Swap pivot value with beginning of array
    std::swap(array[left], array[pivotInd]);

    // Set up to left + 1 and down to right
    int up = left + 1;
    int down  = right;

    do {
        // Increment up while less than or equal to pivot
        while (array[up] <= pivotVal && up != right) {
            up++;
        }
        // Decrement down while greater than pivot
        while (array[down] > pivotVal && down != left) {
            down--;
        }
        // If up less than down, swap
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    } while (up < down);

    // Return pivot to middle by swapping with down
    std::swap(array[left], array[down]);

    return down;
}

template<class T>
void quickSort(std::vector<T>& array, int left, int right) {
    if (left < right) {
        // Partition Array
        int pivotInd = partition(array, left, right);

        // Quicksort Small
        quickSort(array, left, pivotInd - 1);

        // Quicksort Large
        quickSort(array, pivotInd + 1, right);
    }
}

template<class T>
void sort(std::vector<T>& array) {
    // Call quickSort function
    quickSort(array, 0, array.size() - 1);
}


