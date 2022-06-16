#include<bits/stdc++.h> 
bool dp[1001][1001];
string longestPalinSubstring(string s)
{
    // Write your code here.
     memset(dp,false,sizeof(dp));
        int n=s.length();
        int maxlen= 1;
        int idx=0;
        
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
            {    dp[i][i+1]=true;
             if(maxlen<2)
              {
                idx=i;//marker
                maxlen=2;//length
              }           
            }
        }
        
        //for letter >3
        for(int k=3;k<=n;k++){
            
            for(int i=0;i<n-k+1;i++ ){
                //find j
                int j=i+k-1;
                
                if(s[i]==s[j]&&dp[i+1][j-1])
                 {   
                    dp[i][j]=true;
                    if(maxlen<k)
                    {
                        maxlen=k;
                        idx=i;
                    }
                }
            }            
            
        }
                
        return s.substr(idx,maxlen);   
}

// The base cases are:
// P(i, i) = trueP(i,i)=true
// P(i, i+1) = ( S_i == S_{i+1} )
// This yields a straight forward DP solution,
//  which we first initialize the one and two letters 
//  palindromes, and work our way up finding all three 
//  letters palindromes, and so on...
T.C->O(n*n) S.C->O(n*n)
can also be solved using map as caching
