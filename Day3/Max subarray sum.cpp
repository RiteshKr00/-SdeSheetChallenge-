#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
     Two variation one on codesudio and other leetcode
        input:-3 -1 -2
        Output:
        codestudio:0
        Leetcode:-1
    */
    //codestudio
    long long maxi=INT_MIN,curr=0;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(curr<0)
            curr=0;  
         maxi=max(maxi,curr);
    }
    //Leetcode
    // here we calculate curr and upfate maxi for maximum number(-ve/+ve) but if this
    // curr is negative we reset curr to 0 so that if next number is also negative then 
    // curr will store only that -ve number so that we can compare maxi and curr.
    for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr>maxi)
             maxi=curr;
            curr=max(curr,0);            
        }
    
    return maxi;
}
// T.C->O(N) S.C->O(1)
