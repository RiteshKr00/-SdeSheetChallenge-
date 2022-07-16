#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>>s;
    vector<int> ans;
    for(int i=0;i<price.size();i++){
        if(s.empty()||s.top().first>price[i])
            s.push({price[i],1});
        else{
            int x=0;
            while(!s.empty()&&s.top().first<=price[i]){
                    x=x+s.top().second;
                s.pop();
                
            }
            s.push({price[i],x+1});
        }
        ans.push_back(s.top().second);
    }
    return ans;
}