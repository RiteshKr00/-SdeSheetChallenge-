/*
T.C->O(N)  S.C->O(1)
This solution gives time limit error
*/
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int count=0;
    int i=0,j=0;
    while(i<m&&j<n){
        count++;
        if(row1[i]<row2[j]){
            if(count==k){
              return row1[i];
            }
            i++;
        }
        else{
            if(count==k){
                return row2[j];
            }
            j++;
        }
    }
    while(i<m){
        count++;
            if(count==k){
              return row1[i];
            }
            i++;
        }
    while(j<n){
        count++;
            if(count==k){
              return row2[j];
            }
            j++;
        }
}
//Efficient Approch using binary search
/*
similar to finding Median  Just change the condition of assigning high and low
if(k>n&&k>m)
then minimum k-m element must be selected from  1st array to so that even if we select all element
from 2nd we stil have to selct ( k-m )
SO Low=max(0,k-m);it will automatically cover if k>m or k<m;
Now for High--->
either we can select k element when k<n or n when k>n
SO high=min(k,n)
*/
#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n, int m, int k) {
    // Write your code here.
//     int n=a.size();
//     int m=b.size();
    if(n>m)
        return ninjaAndLadoos(b,a,m,n,k);
    int l=max(0,k-m),h=min(k,n);
    
    while(l<=h){
        int cut1=(l+h)/2;
        int cut2=k-cut1;
        
        int lA=cut1==0?INT_MIN:a[cut1-1];
        int lB=cut2==0?INT_MIN:b[cut2-1];
        
        int rA=cut1==n?INT_MAX:a[cut1];
        int rB=cut2==m?INT_MAX:b[cut2];
        
        if(lA<=rB&&lB<=rA){
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