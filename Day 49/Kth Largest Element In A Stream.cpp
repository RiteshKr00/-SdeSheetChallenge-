#include<bits/stdc++.h>
// when there is kth something think of priority queue
//always keep the heap size == K
class Kthlargest {
public:
    priority_queue<int>pq;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
//         since initially k numbers in pool so we push all with negative to convert it into min heap
        for(auto it:arr)
            pq.push(-it);
        //here top element will be current  k th largest      
    }

    void add(int num) {
        // Write your code here.
//         Now Add the element aand remove from top so that size remain K
        pq.push(-num);
        pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
//         top element
        return -pq.top();
    }

};