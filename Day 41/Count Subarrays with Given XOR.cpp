// Pattern :Subarray Sum/Xor/anything Equals K
//similar to  Subarray Sum Equals K
Use Hash Map to store the previously occured xor i.e preXor(~prefix sum) in a map


#include <bits/stdc++.h> 
int subarraysXor(vector<int> &nums, int k)
{
    //    Write your code here.
     unordered_map<int,int>mp;
        int ans=0;
       int presum=0;
        for(int i=0;i<nums.size();i++){
            //it cover the case when presum-k==0
           mp[presum]++;
            presum^=nums[i];            
            if(mp.find(presum^k)!=mp.end()){
                ans+=mp[presum^k];
            }   
            
        }
        //more intutive for loop
        /*
            for(int i=0;i<arr.size();i++){

                    xr ^=arr[i];

                    if(xr == x) count++;

                    if(mp.find(xr ^ x) != mp.end()) count += mp[xr ^ x];

                    mp[xr]++;

                }
        */



                
return ans;
}
