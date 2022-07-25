#include <bits/stdc++.h> 
/*
T.C->O(N)
->sorted the array
->fixed 1st number{i} and 2nd and third is declared as int l=i+1,r=n-1;
now keep checking until we find a sum =k-nums[i];
->once found increment l++ and decrement r--
but before that check whether any duplicate of nums[l] and nums[r] exist or not 
->if exist first  keep miving l pinter till it reaches the last duplicates and
 same in case of r(decement)____>> This makes sure that there is no duplicate in result.

->after first i also do the same if there is any duplicate so that  there is no duplicate in result.

*/
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
     vector<vector<int>> res;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                // cout<<nums[i]<<" ";
            int target=K-nums[i];
        // i != j, i != k, and j != k this case is covered here
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum<target){
                    l++;                   
                }
                else if(sum>target){
                    r--;
                }
                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                     // solution set must not contain duplicate triplets.
                    //remove duplicates from front and back
                    while(l+1<r&&nums[l]==nums[l+1])l++;
                    while(l<r-1&&nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                    
                }
            }
                // //remove 1st element duplicate
                while(i+1<n&&nums[i]==nums[i+1])i++;
            
        }
        return res;
}

// ??HAsh Map Appraoch
// In this approach, firstly, we will hash the indices of all elements in a hashMap. In case of repeated elements, the last occurence index would be stored in hashMap.

// Here also we fix a number (num[i]), by traversing the loop. But the loop traversal here for fixing numbers would leave last two indices. These last two indices would be covered by the nested loop.
// If number fixed is +ve, break there because we can't make it zero by searching after it.
// Make a nested loop to fix a number after the first fixed number. (num[j])
// To make sum 0, we would require the -ve sum of both fixed numbers. Let us say this required.
// Now, we will find the this required number in hashMap. If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet. Push it in answer vector.
// Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
// Update i to last occurence of 1st fixed number to avoid duplicate triplets.
// Return answer vector.
// My HashMap Submission:

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());     //Sorted Array
        if(nums.size() < 3){                // Base Case 1
            return {};
        }
        if(nums[0] > 0){                    // Base Case 2
            return {};
        }
        unordered_map<int , int> hashMap;
        for(int i = 0 ; i < nums.size() ; ++i){     //Hashing of Indices
            hashMap[nums[i]] = i;
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() - 2 ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            for(int j = i + 1 ; j < nums.size() - 1 ; ++j){     //Fixing another number after first number
                int required = -1*(nums[i] + nums[j]);    //To make sum 0, we would require the -ve sum of both fixed numbers.
                if(hashMap.count(required) && hashMap.find(required)->second > j){ //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                    answer.push_back({nums[i] , nums[j] , required});
                }
                j = hashMap.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = hashMap.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return answer;  //Return answer vector.
    }
};