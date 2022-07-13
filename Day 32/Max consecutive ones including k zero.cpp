int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int count=0,l=0,len=0;
    for(int r=0;r<n;r++){
        //if(zero) is there increment its count
      if(arr[r]==0){
          count++;
      }
      //if count of zero in max subarray become greater than given k we pop one from left
       while(count>k){
           if(arr[l]==0){
               count--;
           }
           l++;
       } 
        //update maximum possible length
        len=max(len,r-l+1);
    }
    return len;
}
//Now this can be solved as
// finding the longest window with atmost k zeros
/*
1. first try to include all k zero and make largest length possible
if again number of zero count become equal to k
2.try to remove one zero from left
use loop -> while(arr[i++]!=0);
then update max length till here;
*/
int ans=0;
        for(int l=0,r=0;r<nums.size();r++){
           if(nums[r] == 0)     // current element is 0 - try to pick it             
			if(k == 0)             // if window already picked k zeros, then pop one from left end & pick current  
				while(nums[l++] != 0);      
			else k--;                 // otherwise simply pick it and decrement k   
		ans = max(ans, r - l + 1);   // keep updating ans as max window size till now
        }
return ans;
