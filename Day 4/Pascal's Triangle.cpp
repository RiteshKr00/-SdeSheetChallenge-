#include <bits/stdc++.h> 
void fun(vector<vector<long long int>> &ans,int n,vector<long long int> v){
    if(n==1)
        return;
    vector<long long int> v1;
    v1.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        v1.push_back(v[i-1]+v[i]);
    }
    v1.push_back(v[v.size()-1]);
    ans.push_back(v1);
    fun(ans,n-1,v1);
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> ans;
    vector< long long int> v;
    ans.push_back({1});
    v.push_back(1);
     fun(ans,n,v);
    return ans;
}
