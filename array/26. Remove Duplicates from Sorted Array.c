
int removeDuplicates(int* nums, int numsSize) {
  int cursor = 0;
  int prevVal = -101;

  for(int i = 0; i < numsSize; i++){
    int num = nums[i];

    if(num != prevVal){
      nums[cursor++] = num;
      prevVal = num;
    }
  }

  return cursor;
}

// 모범답안
int removeDuplicates2(int* nums, int numsSize) {
  if (numsSize == 0) return 0; // 예외 처리

  int cursor = 1; // 첫 번째 원소는 이미 고유하므로 1부터 시작
  for (int i = 1; i < numsSize; i++) {
      // 현재 값(nums[i])이 바로 앞의 고유한 값(nums[cursor-1])과 다를 때만 기록
      if (nums[i] != nums[cursor - 1]) {
          nums[cursor] = nums[i];
          cursor++;
      }
  }
  return cursor;
}