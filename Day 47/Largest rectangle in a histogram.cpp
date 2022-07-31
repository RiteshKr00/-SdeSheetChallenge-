// Using Next Smaller and Previous Smaller
#include<bits/stdc++.h> 
int largestRectangle(vector < int > & heights) {
   // Write your code here
      stack<int>s;
        int n=heights.size();
        
        vector<int>lse(n);
        vector<int>rse(n);
        ///find left small
        for(int i=0;i<n;i++){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            //if stack become empty asssign the lse the left boundary i.e. 0
            if(s.empty())
                lse[i]=0;
            else
                lse[i]=s.top()+1;
                
            //push the current element index in stack(Maintain Monotonic nature)
            
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                rse[i]=n-1;
            else
                rse[i]=s.top()-1;
            
            s.push(i);
        }
        
        int  maxm=INT_MIN;
        for(int i=0;i<n;i++){
           
            int a=heights[i]*(rse[i]-lse[i]+1);
           
            maxm=max(a,maxm);      
            
        }
        
        return maxm; 
     
 }


 //Try to do in One PASS-->

 