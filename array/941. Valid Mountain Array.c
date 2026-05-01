#include <stdbool.h>

// 1. tow pointer approach
bool validMountainArray(int *arr, int arrSize) {
  int left = 0;
  int right = arrSize - 1;

  for (int i = 0; i < arrSize - 1; i++) {
    int curr = arr[i];
    int next = arr[i + 1];

    if (curr >= next) {
      left = i;
      break;
    }
  }

  for (int i = right; i > 0; i--) {
    int curr = arr[i];
    int prev = arr[i - 1];

    if (curr >= prev) {
      right = i;
      break;
    }
  }

  return arrSize > 2 && left == right;
}

// 2. one pass approach
bool validMountainArray2(int *arr, int arrSize) {
  int i = 0;

  while (i < arrSize - 1 && arr[i] < arr[i + 1]) {
    i++;
  }

  if (i == 0 || i == arrSize - 1) {
    return false;
  }

  while (i < arrSize - 1 && arr[i] > arr[i + 1]) {
    i++;
  }

  return i == arrSize - 1;
}