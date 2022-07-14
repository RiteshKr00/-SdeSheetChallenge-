#include<bits/stdc++.h>
// T>C->O((2^n)*(N))
    void solve(vector<vector<int>> &ans,vector<int>& nums,vector<int> v,int n,int k){
      ans.push_back(v);
        for(int i=k;i<n;i++){
            if(k<i&&nums[i-1]==nums[i])continue;
           v.push_back(nums[i]);
           solve(ans,nums,v,n,i+1);
           v.pop_back();
           
       }
       
       
   }

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int>ds;
    sort(arr.begin(),arr.end());
    solve(ans,arr,ds,n,0);
    return ans;
}