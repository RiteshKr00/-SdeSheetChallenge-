/*
Can be solved using HashMap and priority queue
T.C->O(klogD+N+klogk)(pop from pq,traverse,sort the answer)
S.C->O(N)Map
M2
T.C->O(n+klogk)
S.C->O(N)Map
Use frequncy as index 
store every element in array of vector.
*/


#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int>ans;
    map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    vector<int> v[n+1];
    for(auto it=mp.begin();it!=mp.end();it++){
        v[it->second].push_back(it->first);
    }
    int count=0;
    for(int i=n;i>=0;i--){
        for(auto x:v[i]){
            count++;
            ans.push_back(x);
            if(count==k){
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
    }
    
}