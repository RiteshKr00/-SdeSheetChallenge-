// Similar to unbounded knapsack and analogus to subset sum problem
// T.C-O(n*value) S.C->O(n*value)
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    int dp[11][2001];
    
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
    for(int i=1;i<=value;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=value;j++){
              if(denominations[i-1]<=j)
                 dp[i][j]=dp[i][j-denominations[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
    }
    return dp[n][value];
    
}