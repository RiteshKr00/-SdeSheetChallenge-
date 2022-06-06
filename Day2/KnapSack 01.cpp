/****************************************************************
Start with recursive approach 
I have choice whether to include wt or not
if(current wt<W)then we have two choice so we will include/or Not depend on which return maximum
else dont pick the element
#Memoise is similar to Recursive just use a extra 2d array to store the result of subproblems
#Tabulation /Top down approach
T.C->O(N^2) S.C->O(N^2)
*****************************************************************/
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    int dp[1001][1001];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0)
                dp[i][j]=0;
                else if(weights[i-1]<=j){
                    dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
                }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}