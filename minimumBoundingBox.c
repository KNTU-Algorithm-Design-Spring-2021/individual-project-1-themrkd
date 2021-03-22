#include <stdio.h>
#include <float.h>

#define SIZE 10 // size for testing

void findMinMax(float array[], int low, int high, float *min, float *max);

int main(void) {
    // sample points
    float xArray[SIZE] = {-4, 6, 1, 0, 12, -9, 7, 3, 2, 5};
    float yArray[SIZE] = {8, 34, -22, 11, 13, 18, 9, -43, 32, 0};

    float xMin = FLT_MAX, xMax = FLT_MIN, yMin = FLT_MAX, yMax = FLT_MIN;
    findMinMax(xArray, 0, SIZE - 1, &xMin, &xMax);
    findMinMax(yArray, 0, SIZE - 1, &yMin, &yMax);

    printf("Box vertices are: (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n", xMin, yMin, xMin, yMax, xMax, yMin, xMax, yMax);
}

void findMinMax(float array[], int low, int high, float *min, float *max) {
    // if subarray has 1 elemnt:
    if (high == low) {
        if (array[low] < *min) {
            *min = array[low];
        }
        if (array[low] > *max) {
            *max = array[low];
        }
        return;
    }
    //if subarray has 2 elements:
    if (high - low == 1) {
        if (array[low] < array[high]) {
            if (array[low] < *min) {
            *min = array[low];
            }
            if (array[high] > *max) {
            *max = array[high];
            }
        
        } else {
            if (array[high] < *min) {
            *min = array[high];
            }
            if (array[low] > *max) {
            *max = array[low];
            }
        }
        return;
    }
    // recursively for subarrays that has more than 2 elements:
    int middle = (low + high) / 2;

    findMinMax(array, low, middle, min, max);

    findMinMax(array, middle + 1, high, min, max);
}