#include <limits.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int length = m + n;
    m--;
    n--;

    for(int i = length - 1; i >=0; i--){
      int num1 = m >= 0 ? nums1[m] : INT_MIN;
      int num2 = n >= 0 ? nums2[n] : INT_MIN;

      if(num1 < num2){
        nums1[i] = num2;
        n--;
      }else{
        nums1[i] = num1;
        m--;
      }
    }
}