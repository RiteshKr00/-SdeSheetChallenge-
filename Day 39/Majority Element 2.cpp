/*
Same intution if (n/2>) then there exist one majority
similarly if (n/3>) then there exist two majority
so we use two variable to store two possible candidate of majority/

*/

#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int N=floor(arr.size()/3);
    int c1=-1,c2=-1;
    int cnt1=0,cnt2=0;
    for(int el:arr){
        if(el==c1)cnt1++;
        else if(el==c2)cnt2++;
        else if(cnt1==0){
            c1=el;
            cnt1++;
        }
        else if(cnt2==0){
            c2=el;
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;            
        }
    }
    vector<int>ans;
    cnt1=0;
    for(int i:arr){
        if(i==c1)
            cnt1++;
    }
    cnt2=0;
    for(int i:arr){
        if(i==c2)
            cnt2++;
    }
    if(cnt1>N)
        ans.push_back(c1);
    if(cnt2>N)
        ans.push_back(c2);
return ans;
}