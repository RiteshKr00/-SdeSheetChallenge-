// T.C->O(N.Log(K))
// Auxillary sapce(N)
// priority queue str 
// pair<value,pair<array indx in matrice , element index in Array>>
#include<bits/stdc++.h>
typedef pair<int,pair<int,int>> ppi;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
   priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    //store val + array indx + element index in Array
    for(int i=0;i<k;i++){
        pq.push({kArrays[i][0],{i,0}});
    }
    
    
    while(!pq.empty()){
    auto curr=pq.top();
    pq.pop();
    int x=curr.second.first;
    int y=curr.second.second;
    //push value in answer
    ans.push_back(curr.first);
      if(y+1<kArrays[x].size()){
          pq.push({kArrays[x][y+1],{x,y+1}});
      }  
        
    }
    
    return ans;
    
    
}
