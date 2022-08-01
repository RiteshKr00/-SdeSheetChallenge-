#include<bits/stdc++.h>
// O((N-k)*k)
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> ans;
    int max,j;
    for(int i=0;i<=(nums.size()-k);i++){
         max=nums[i];
        for(j=1;j<k;j++){
            if(nums[i+j]>max){
                max=nums[i+j];
            }
        }
        ans.push_back(max);
    }
    return ans;
}

//optimal soln-->