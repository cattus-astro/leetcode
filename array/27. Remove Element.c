int removeElement(int* nums, int numsSize, int val) {
  int cursor = 0;
  
  for(int i = 0; i < numsSize; i++){
    int num = nums[i];

    if(num != val){
      nums[cursor++] = num;
    }
  }

  return cursor;
}