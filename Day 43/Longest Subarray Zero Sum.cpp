#include <bits/stdc++.h> 
// use hashmap
int LongestSubsetWithZeroSum(vector < int > arr) {

  unordered_map<int,int>ans;
   ans[0]=-1;
   int len=0;
   int sum=0;
   for(int i=0;i<arr.size();i++){
       sum+=arr[i];
       if(ans.find(sum)!=ans.end()){
           len=max(len,i-ans[sum]);
       }
       else{
           ans[sum]=i;
       }
   }
   return len;

}