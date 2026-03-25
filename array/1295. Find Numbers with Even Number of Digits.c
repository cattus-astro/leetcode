int findNumbers(int* nums, int numsSize) {
  int result = 0;
  
  for(int i = 0; i < numsSize; i++) {
      int num = nums[i];
      int cnt = 0;
      
      while(num > 0){
          num = num / 10;
          cnt++;
      }
      
      if(cnt % 2 == 0){
          result++;
      }
  }
  
  return result;
}