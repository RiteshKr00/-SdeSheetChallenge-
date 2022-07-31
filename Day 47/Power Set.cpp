/*Iterative solution
Total number=2^N so each Number from 1 t0 2^N will have different binary bits-->
Corresponding to which we choose char/element from the given array/string
If ith bit in counter is set Print ith element from set for this subset


*/
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n=v.size();
    vector<vector<int>>ans;
    for(int i=0;i<(1<<n);i++){
        vector<int>subset;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
                subset.push_back(v[j]);
        }
        ans.push_back(subset);
    }
    return ans;
}

//recursive
class Solution {
public:
   void helper(vector<vector<int>> &ans,vector<int>& nums,vector<int> v,int n,int k){
       if(k==n){
           ans.push_back(v);
           return;
       }
       else{
           helper(ans,nums,v,n,k+1);
           v.push_back(nums[k]);
           helper(ans,nums,v,n,k+1);
           // v.pop_back();
       }
   }    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v;
        helper(ans,nums,v,n,0);
        return ans;
    }
};