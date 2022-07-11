//two ptr
// T.C->O(N) S.C:O(1)
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    int i=0,j=n-1;
    long ans=0,lmax=0,rmax=0;    
    while(i<=j){
        if(lmax<rmax){
            if(lmax<arr[i])
                lmax=arr[i];
            else
                ans+=lmax-arr[i];
            i++;
        }
        else{
            if(rmax<arr[j]){
                rmax=arr[j];
            }
            else
                ans+=rmax-arr[j];
            j--;
        }
    }
    return ans;
}
// Stack approach