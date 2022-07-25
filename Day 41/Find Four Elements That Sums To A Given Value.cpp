// Hash Map solution
#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    unordered_map<int, pair<int, int>> mp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            mp[sum] = {i, j};
        }
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int left = target - (arr[i] + arr[j]);
            
            if(mp.find(left) != mp.end())
            {
                pair<int, int> it = mp[left];
                    int k = it.first;
                    int l = it.second;
                    
                    if(i != k && i != l && j != k && j != l)
                        return "Yes";
            }
        }
    }
    
    return "No";
}
//two pointer solution

#include <bits/stdc++.h> 
string fourSum(vector<int> nums, int target, int n) {
    // Write your code here.
    set<vector<int>>v;
        sort(nums.begin(),nums.end());
       
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int start=j+1;
                int end=n-1;
                while(start<end)
                {
                    long long int sum=(long long int)nums[i]+nums[j]+nums[start]+nums[end];
                    if(sum>target)
                    {
                        end--;
                    }else if(sum<target)
                    {
                        start++;
                    }
                    else
                    {
       return "Yes";
                    }
                }
                while(j<n-1 && nums[j]==nums[j+1])
                {
                    j++;
                }
            }
                while(i<n-1 && nums[i]==nums[i+1])
                {
                    i++;
                }
               }
                
            return "No";
}