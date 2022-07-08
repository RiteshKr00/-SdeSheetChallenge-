#include<bits/stdc++.h>
// T.c->O(N^2)//due to two loop
//so we use priority key(min heap) to find min which reduces T.C->O(N*(E+logN))
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
      vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);
     int src=1;
    key[src]=0;
     //we will have only n-1 edge in spanning tree
    for(int i=0;i<n-1;i++){
        //find minKey=having least dist and not inluded in mst ;
        int mini=INT_MAX, idx;
        for(int j=1;j<=n;j++){
            if(!mst[j]&&key[j]<mini){
                mini=key[j]; 
                idx=j;
            }
        }
        //
        mst[idx]=true;
        
        for(auto it:adj[idx]){
            int v=it.first;
                int weight=it.second;
                //here we only update the ksy if dist of idx to v is less than current value in key
            if(!mst[v]&&key[v]>weight){
               key[v]=weight;     
                parent[v]=idx;
            }
        }
        
        
    }
//here parent arry store the value of nodes parent

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;

    
}
