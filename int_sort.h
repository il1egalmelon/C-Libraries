#pragma once
#include <iostream>
#include <vector>

namespace sort {
    void quicksort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = arr[(low + high) / 2];
            int left = low;
            int right = high;
            while (left <= right) {
                while (arr[left] < pivot) {
                    left++;
                }
                while (arr[right] > pivot) {
                    right--;
                }
                if (left <= right) {
                    std::swap(arr[left], arr[right]);
                    left++;
                    right--;
                }
            }
            quicksort(arr, low, right);
            quicksort(arr, left, high);
        }
    }

    std::vector<int> isort(std::vector<int> x) {
        std::vector<int> arr = x;
        quicksort(arr, 0, arr.size() - 1);
        // for (int i = 0; i < arr.size(); i++);
        return arr;
    }
}
