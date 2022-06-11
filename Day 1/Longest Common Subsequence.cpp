
// Notes

Start comparing from last and check every case
Base Case when one of is empty



// recursive to memoize
 int dp[1001][1001]={-1};
    int maxLen(string s1,string s2,int m,int n,vector<vector<int> > &dp){
        if(m==0||n==0){
            return 0;
        }        
        if(s1[m-1]==s2[n-1]){
            return dp[m][n]=1 + maxLen(s1,s2,m-1,n-1,dp);
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        else{
            return dp[m][n]=max(maxLen(s1,s2,m,n-1,dp),maxLen(s1,s2,m-1,n,dp));
        }        
        
    }

   // tabulation 
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int> >dp(text1.length()+1, vector<int>(text2.length()+1));
        int dp[1001][1001];
        for(int i=0;i<=text1.length();i++){
            for(int j=0;j<=text2.length();j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }    
       return dp[text1.length()][text2.length()];
        //maxLen(text1,text2,text1.length(),text2.length(),dp);
        
    }