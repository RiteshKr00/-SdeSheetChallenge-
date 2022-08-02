#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.    
    priority_queue<int>pq;
    for(int i=0;i<size;i++){
        pq.push(arr[i]);
    }
    while(K!=1)
    {    pq.pop();K--;}
    return pq.top();
}
// T.C->O(n+kLogn)

//quick select can also be used to solve in O(n)
// try to equate pivot = target index