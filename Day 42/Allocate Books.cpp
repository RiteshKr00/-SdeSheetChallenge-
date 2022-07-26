#include<bits/stdc++.h>
/*
We are required to find the minimum number of pages among all possible 
maximum number of pages of allocations. So, in the worst case, the minimum
 possible will be minimum pages among all given books.
Now, we know the lowest possible answer and the maximum possible answer and 
for general cases, the answer will lie in between these edge cases. 
Thus, we have a search space. This search space will be sorted.
 Guess what? We reached our approach to use a binary solution.


*/
bool isPossible(int days, long long int limit, vector<int> time){
    int dayRequired=1;
    long long int minStudied=0;
    for(int i=0;i<time.size();i++){              
        if(minStudied+time[i]>limit){
            dayRequired++;
            
            minStudied=time[i];
            //check after each update of minStudied
            if(minStudied>limit)
            return false; 
            
            if(dayRequired>days)
                return false;
        }
        else{
            minStudied+=time[i];
        }
         
    }
    return true;
    
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
    long long int low=time[0];
    long long int high=0;
    for(int i=0;i<m;i++){
        high+=time[i];
//         low=min(low,time[i]);
        if(low<time[i])
            low=time[i];
    }
    long long int result;
   while(low<=high){
       long long int mid=low+(high-low)/2;
       if(isPossible(n,mid,time)){
           //update result
           result=mid;
           high=mid-1;
       }
       else{
           low=mid+1;
       }             
   } 
    return result;    
    
}