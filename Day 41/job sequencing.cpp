#include<bits/stdc++.h>
// T.C->O(N^2)  S.C-> O(N )
//sort according to profit and use time slot vector to fill.
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int profit=0;
    sort(jobs.begin(),jobs.end(),[](vector<int> a,vector<int> b){
        return a[1]>b[1];
    });
    vector<int>slot(3001,-1);
    for(int i=0;i<jobs.size();i++){
        int deadline=jobs[i][0];
        for(int j=deadline;j>0;j--){
            if(slot[j]==-1){
                slot[j]=1;
                profit+=jobs[i][1];
                break;
            }
        }
    }
    
    return profit;
    
}

// M2  using priority queue left 
// T.C->O( )  S.C-> O( )



