#include <bits/stdc++.h> 
/*
T.C->O(N)
->sorted the array
->fixed 1st number{i} and 2nd and third is declared as int l=i+1,r=n-1;
now keep checking until we find a sum =k-nums[i];
->once found increment l++ and decrement r--
but before that check whether any duplicate of nums[l] and nums[r] exist or not 
->if exist first  keep miving l pinter till it reaches the last duplicates and
 same in case of r(decement)____>> This makes sure that there is no duplicate in result.

->after first i also do the same if there is any duplicate so that  there is no duplicate in result.

*/
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
     vector<vector<int>> res;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                // cout<<nums[i]<<" ";
            int target=K-nums[i];
        // i != j, i != k, and j != k this case is covered here
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum<target){
                    l++;                   
                }
                else if(sum>target){
                    r--;
                }
                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                     // solution set must not contain duplicate triplets.
                    //remove duplicates from front and back
                    while(l+1<r&&nums[l]==nums[l+1])l++;
                    while(l<r-1&&nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                    
                }
            }
                // //remove 1st element duplicate
                while(i+1<n&&nums[i]==nums[i+1])i++;
            
        }
        return res;
}