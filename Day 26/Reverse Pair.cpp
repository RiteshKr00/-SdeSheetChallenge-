#include <bits/stdc++.h> 
int merge(vector<int> &arr,vector<int>temp,int left,int mid,int right){
    int i=left;
    int j=mid;
    int k=left;
    int count=0;
    while(i<=mid-1&&j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            if(arr[i]>2*arr[j])
            temp[k++]=arr[j++];
            //calculate number of inversion
            count=count+mid-i;
        }
    }
    while(i<mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    
    for(int i=left;i<=right;i++){
        arr[i]=temp[i];
    }
    return count;
}

int mergesort(vector<int> &arr,vector<int>temp,int left,int right){
    //divide array into two parts
    int count=0,mid;
    if(left<right)
    {
         mid=(left+right)/2;
        count +=mergesort(arr,temp,left,mid);
         count +=mergesort(arr,temp,mid+1,right);
         count +=merge(arr,temp,left,mid+1,right);
    }
    return count;
}


int reversePairs(vector<int> &arr, int n){
        // Write your code here.
    //use Merge sort 
    vector<int>temp(n);
   return mergesort(arr,temp,0,n-1);   
}

// T.C:O(nlogn)
// But giving Tle on code studio site