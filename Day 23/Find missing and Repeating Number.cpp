
#include <bits/stdc++.h> 
//Traverse the array. While traversing, use the absolute value of every element 
//as an index and make the value at this index as negative to mark it visited. 
//If something is already marked negative then this is the repeating element. 
//To find missing, traverse the array again and look for a positive value.
// T.C->O(N) 
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int i;
    int a,b;
  
    for (i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            b=abs(arr[i]);
    }
  
    for (i = 0; i < n; i++) {
        if (arr[i] > 0)
            a=i + 1;
    }
    return {a,b};
}
//Xor--->