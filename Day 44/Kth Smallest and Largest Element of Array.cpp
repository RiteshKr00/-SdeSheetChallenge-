// Pattern whenever there is kth something think of priority queue
// T.C-O(NLogk)
// S.c-O(k+1)

#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
    
    int kthLargest=0;
    int kthSmallest=0;
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    vector<int>ans(2);
    
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    ans[0]=maxh.top();
    
    for(int i=0;i<n;i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            minh.pop();
        }
    }
    ans[1]=minh.top();
    
    return ans;
}

// Two more approach quicksort and binary sort
//quick select

// T.c->O(n)
int partition(vector<int> &arr, int lo, int hi){
    int j=lo-1;
    for(int i=lo;i<hi;i++){
        if(arr[i]<=arr[hi]){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[hi]);
    return j+1;  
}



int randPartition(vector<int> &arr, int lo, int hi){
    //random partion to decrese worst case
    int random=rand()%(hi-lo+1)+lo;
    swap(arr[hi],arr[random]);
    return partition(arr,lo,hi);
}


int quicksort(vector<int> &arr, int lo, int hi,int target){
    int pivot=randPartition(arr,lo,hi);
    if(pivot==target)
        return arr[pivot];
    else{
        return pivot>target?quicksort(arr,lo,pivot-1,target):
        quicksort(arr,pivot+1,hi,target);
    }
}


vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    vector<int>v(2);
   int lo=0;
    int hi=n-1;
    int smallTarget=k-1;
    int largeTarget=n-k;
    v[1]=quicksort(arr,lo,hi,largeTarget);
    v[0]=quicksort(arr,lo,hi,smallTarget);
    return v;
    
}