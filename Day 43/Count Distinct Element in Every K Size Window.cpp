#include<bits/stdc++.h>
T.C->O(N)  S.C->O(K)
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int> ans;
    map<int,int>mp;
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    for(int i=k;i<arr.size();i++){
        if(mp[arr[i-k]]<2)
            mp.erase(arr[i-k]);
        else
            mp[arr[i-k]]--;
        mp[arr[i]]++;
         ans.push_back(mp.size());           
    }
	return ans;
}
