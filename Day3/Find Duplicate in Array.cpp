/*
Two type of Solution
I.Modify array
sort/use set/use negative Marking As i did
II.without Modify Array
use Binary Search on Property in case duplicate is present
"For the given number, the count of numbers less than or equal to it, exceeds 
the number itself"
so we find the first smallest number which satisfy above statement
->we can do that either by cheking linerly from 1 to n
-> or apply binary search if condition satisfy move left / decrement the number to check 
otherwise increment.
T.C->O(NlogN) S.C->O(1)
Two more Methods setbits and Floyd's Tortoise and Hare(To be solved*)
*/


//MYcode
// T.C->O(N) S.C->O(1)
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]<0)
          {  ans=abs(arr[i]);
          break;}
        arr[abs(arr[i])-1]*=-1;
//         cout<<arr[abs(arr[i])-1]<<endl;
    }
    return ans;
  
}
