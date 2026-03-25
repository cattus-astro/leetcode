void duplicateZeros(int* arr, int arrSize) {
  // 핵심: 배열이 실제 위치할 곳을 시뮬레이션. 0으로 끝나게 될 경우에 대한 예외처리
  int zeroCnt = 0;
  int lastIdx = arrSize - 1;
  int padding = 0;

  for(int i = 0; i + zeroCnt < arrSize; i++){
    int num = arr[i];

    zeroCnt += num == 0 ? 1 : 0;

    if(i + zeroCnt == arrSize){
      arr[lastIdx] = 0;
      zeroCnt--;
      padding++;
    }
  }

  for(int i = lastIdx - padding, j = lastIdx - zeroCnt - padding; j >= 0; j--){
    int num = arr[j];

    arr[i--] = num;

    if(num == 0){
      arr[i--] = num;
    }
  }
}