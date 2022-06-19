/*
T.C->O( N+NlogN)  S.C-> O(n) due to extra structure used
sort according to finish time and select those whose 
start time is just equal or greater to finish time of previous work
*/
#include<bits/stdc++.h>
bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int ans=1;
    int n=start.size();
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        v[i].first=start[i];
        v[i].second=finish[i];
    }
    sort(v.begin(),v.end(),comp);
    int i=0;
    
    for(int j=1;j<n;j++){
        if(v[j].first>=v[i].second){
            ans++;
            i=j;
        }
    }   
    return ans;
}