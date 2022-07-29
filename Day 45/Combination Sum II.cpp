#include<bits/stdc++.h>
// use Recursive Function T.C->O(2^N)
void helper(vector<int> &arr, int n, int target,int idx, vector<vector<int>> &ans,vector<int>t){
    //base
    if(target==0){
            ans.push_back(t);
        }
    if(idx==n){       
        return;            
    }    
    for(int i=idx;i<n;i++){
        if(i!=idx&&arr[i]==arr[i-1])continue;
            t.push_back(arr[i]);
            helper(arr,n,target-arr[i],i+1,ans,t);
            t.pop_back();        
    }    
    
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<vector<int>> ans;
    vector<int>t;
    sort(arr.begin(),arr.end());
    helper(arr,n,target,0,ans,t);    
    return ans;    
}
