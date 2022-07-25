#include<bits/stdc++.h>
// T.C->O(log(min(n,m))) S.C->O(1)
/*
1# SInce Median is middle or sum(even case) of middle in a sorted array
2# I try to partition/divide both array in such a way that some elements from 1st and some from
*2nd is selcted and put in 1st part(length=N+m+1/2) and remaining in 2nd part and we select 
*element from start for first part to ensure that 1st part has all elemnt 
*less than 2nd part's each element
3# Now i have to decide only how may element i will choose from 1st arry for first part
  and it will automatically decide no of element to be chosen from 2nd array for 1st part
     i.e (N+M+1)/2-element chosen from 1st array
4# So to choose where to put a cut in first array we use binary search and some condition
   calculated using given condition
   i.e if cut1=n/2 then lA=cut1-1  rA=cut1
   similarly cut2=(n+m+1)/2-cut1   then lB=cut2-1  rB=cut2
   and lA<rB&&lB<rA
   otherwise change search space of 1st array i.e either move low to right or high to left
*/


double median(vector<int> a, vector<int> b)
{
    // Write your code here.s
    int n=a.size();
    int m=b.size();
    if(n>m)
        return median(b,a);
    int l=0,h=n;
    
    while(l<=h){
        int cut1=(l+h)/2;
        int cut2=((n+m+1)/2)-cut1;
        
        int lA=cut1==0?INT_MIN:a[cut1-1];
        int lB=cut2==0?INT_MIN:b[cut2-1];
        
        int rA=cut1==n?INT_MAX:a[cut1];
        int rB=cut2==m?INT_MAX:b[cut2];
        
        if(lA<rB&&lB<rA){
            if((n+m)%2==0){
                return (double)(max(lA,lB)+min(rA,rB))/2;
            }
            else
                return max(lA,lB);
        }
        else if(lA>rB){
            h=cut1-1;
        }
        else{
            l=cut1+1;
        }        
    }
    
    
}
