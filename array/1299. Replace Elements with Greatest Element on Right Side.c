int *replaceElements(int *arr, int arrSize, int *returnSize) {
  *returnSize = arrSize;

  int max = -1;

  for (int i = arrSize - 1; i >= 0; i--) {
    int temp = arr[i];
    arr[i] = max;
    max = max > temp ? max : temp;
  }

  return arr;
}