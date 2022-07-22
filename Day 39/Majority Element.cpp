// can be solved using sorting also in O(NLOGN)

//MAP T.C->O(N) S.C->O(N)
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second>floor(n/2))
            return it->first;
    }
    
    return -1;
}

// Moore's voting algo Left to do????????
// 2 step 
// 1st find candidate 2nd verify it
// Intution==========
// Let Majority is x .ifit apperars on left prefix 
// then its count must be greater than N/2 .
// If not then it must  appear on last suffix to be the majority
// element
// e.g 7 7 5 7 5 1 | 5 7 | 5 5 7 7 | 5 5 5 5 

/* Code
int  count=0;
int candidate=0;
for(int num:nums){
    if(count==0)
    candidate=num;
    if(num==candidate) count+=1;
    else count--;
}
*/