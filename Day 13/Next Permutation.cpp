/*
a) Traverse from the right and find the first item that is not following the descending order. For example in “abedc”, the character ‘b’ does not follow the descending order.
b) Swap the found character with the closest greater (or smallest greater) element on the right side of it. In the case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, the string becomes “acedb”.
c) After swapping, reverse the string after the position of the character found in step a. After reversing the substring “edb” of “acedb”, we get “acbde” which is the required next permutation. 
*/

#include <bits/stdc++.h> 
 void rev(vector<int> &nums,int i){
         int  j = nums.size() - 1;
        while (i <= j) {
            swap(nums[i],nums[j]);
            i++;
            j--;
            }           
    }
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int i=n-2;
      //find the pair where nums[i+1]<num[i]
    while(i>=0&&permutation[i+1]<=permutation[i])
        i--;
    if(i>=0){
        int j=n-1;
          //find the smallest greater from right side
        while(permutation[j]<=permutation[i])
            j--;
        swap(permutation[j],permutation[i]);
    }
    rev(permutation,i+1);
        return permutation;
}