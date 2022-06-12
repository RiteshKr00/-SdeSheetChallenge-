// T.C->O(n*n)<-S.C 
#include<bits/stdc++.h> 
int dp[101][101];
      bool isPal(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j])
            {
                i++;j--;
            }
            else
                return false;
        }
        return true;
    }
    int cutter(string s,int i,int j){
        //base case
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1){
          return dp[i][j];
        }        
        
        if(isPal(s,i,j))
            return 0;
        int min=INT_MAX;
        for(int k=i;k<j;k++){
            
            // int cnt=cutter(s,i,k)+cutter(s,k+1,j)+1;
            int left,right;
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else
               left=cutter(s,i,k);
            
             if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else
               right=cutter(s,k+1,j);
            
            int cnt=left+right+1;
            
            if(cnt<min)
                min=cnt;
        }
        return dp[i][j]=min;
        
    }


int palindromePartitioning(string str) {
    // Write your code here
     memset(dp,-1,sizeof(dp));
        return cutter(str,0,str.length()-1);
}
