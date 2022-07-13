#include<bits/stdc++.h>
//Monotonic stack question
vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    // Write your code here.
    stack<int>s;
s.push(nums[n-1]);
    nums[n-1]=-1;
for(int i=n-2;i>=0;i--){
    while(!s.empty()&&s.top()>=nums[i])
    s.pop();
    int t=nums[i];
    if(!s.empty()){
       nums[i]=s.top();
    }
    else 
        nums[i]=-1;
    s.push(t);
}

return nums;
}