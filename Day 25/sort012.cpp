#include <bits/stdc++.h> void sort012(int *arr, int n)
{
   //   Write your code here
    int low = 0;
   int mid = 0;
   int high = n-1;
    
    while(mid<=high)
    {
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++; 
            mid++;    
        }
        
        else if(arr[mid]==1)
         mid++;
        
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
/*
ARR[MID]==0  (SWAP(low and mid index element) and low++,mid++)
ARR[MID]==1  ( mid++)
ARR[MID]==2  (SWAP(mid and high index element) and high--; because last element may be 0,1 ;then check again 
*/