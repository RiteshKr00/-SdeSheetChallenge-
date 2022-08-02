//Simmple Brute force is find all sum and push it in priority queue.
// The first K element will at top will be the answer
// T.C->O(N^2)S.C->O(N^2)

// Alternative approach 
1.sort the both Array 
2.take a priority queue to store the sum with their indices(so that we can further deduce next pair)
3.Also take a set to ensure that once a pair is taken is not used again.
4.now simply initailise the Max heap with maxSum possible  that will be(sum with index(n-1,n-1) )
5.now pop the current head from priority queue and store it in the result.
 a.Now we have two options/pair i.e sum with indices (Suppose previous indices are(i,j)) 
 at(i,j-1)&(i-1,j);

 Note:Since we depend on current element at top for next(indices) it will generate
 2^n pairs which will easily cover the k element and thats why we use set to avoid overlapping
T.C->O(NlogN)
S.C->O(N)
 //Code:
 #include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>s;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int sum=a[n-1]+b[n-1];
    pq.push({sum,{n-1,n-1}});
    s.insert({n-1,n-1});
    vector<int>res;
    for(int i=0;i<k;i++){
        int sum=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        res.push_back(sum);
        pq.pop();
        //if first encounter
        //first pair
        if(s.find({x-1,y})==s.end()){
             pq.push({a[x-1]+b[y],{x-1,y}});
             s.insert({x-1,y});
        }
        //second pair
         if(s.find({x,y-1})==s.end()){
             pq.push({a[x]+b[y-1],{x,y-1}});
             s.insert({x,y-1});
        }       
    }
    return res;   
    
}


