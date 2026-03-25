/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>
 
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  int* result = (int*)malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;
  
  int leftCursor = 0;
  int rightCursor = numsSize - 1;
  int idx = numsSize - 1;
  
  while(leftCursor <= rightCursor){
      int left = nums[leftCursor];
      int right = nums[rightCursor];
      
      if(abs(left) < abs(right)){
          result[idx--] = right * right;
          rightCursor--;
      }else{
          result[idx--] = left * left;
          leftCursor++;
      }
  }
  
  
  return result;
}