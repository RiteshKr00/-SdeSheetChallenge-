/*
Similar to Merge K sorted array
first merge
 than find Middle element

*/


#include<bits/stdc++.h>
typedef pair<int,pair<int,int>> ppi;

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    vector<int> a;
    
    for(int i=0;i<matrix.size();i++){
    pq.push({matrix[i][0],{i,0}});
    }
    
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        int x=curr.second.first;
        int y=curr.second.second;
        a.push_back(curr.first);
        if(y+1<matrix[x].size())
            pq.push({matrix[x][y+1],{x,y+1}});
    }
    return a[a.size()/2];
    
}