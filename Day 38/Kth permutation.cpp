#include<bits/stdc++.h>
int factorial(int n){
    if(n==0||n==1)
        return 1;
    return n*factorial(n-1);
}

string kthPermutation(int n, int k) {
    // Write your code here.
    vector<char>s;
    for(int i=0;i<n;i++){
        s.push_back('1'+i);
    }
    string ans;
     k--;
     while(s.size()>=1){
         int cnt=factorial(s.size()-1);
//          cout<<cnt<<endl;
         int x=k/cnt;
         int rem=k%cnt;
         k=rem;
         if(k>=0){
             ans.push_back(s[x]);
             s.erase(s.begin()+x);
         }
//          cout<<"remaing array \n";
//          for(auto it:s){
//              cout<<it<<" ";
//          }
       }  
    return ans;
}
