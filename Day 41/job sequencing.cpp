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
// T.C->O(NLOGN+(N+N{while loop will work/run for N time only}) )  S.C-> O(N)
#include<bits/stdc++.h>
//priority queue has third argument as class type and a operator So to make custom 
// priority queue we have to write own function and overload operator function
struct compare{
    bool operator()(vector<int> &a,vector<int> &b){
        return a[1]<b[1];        
    }
};
//priority queue has third argument as class type and a operator So to make custom 
// priority queue we have to write own function and overload operator function

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int profit=0;
    sort(jobs.begin(),jobs.end(),[](vector<int> a,vector<int> b){
        return a[0]<b[0];
    });
//     vector<int>slot(3001,-1);
    priority_queue<vector<int>,vector<vector<int>>,compare>pq;
    for(int i=jobs.size()-1;i>=0;i--){
        int slot;
       if(i==0){
           slot=jobs[i][0];
       }
     else{
           slot=jobs[i][0]-jobs[i-1][0];
       }
       pq.push(jobs[i]);
        //
        while(slot>0&&pq.size()>0){
            auto x=pq.top();
            pq.pop();
            profit+=x[1];
            slot--;
        }
        
    }    
    return profit;
    
}




