int findMaxConsecutiveOnes(int* nums, int numsSize) {  
  int result = 0;
  int acc = 0;
  
for(int i =0; i < numsSize; i++){
    acc = nums[i] > 0 ? acc+1: 0;
    
    if(result < acc){
        result = acc;
    }
  }
  
  return result;
}