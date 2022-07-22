#include <bits/stdc++.h> 
//first think of reursive solution but it gives exponential time complexity
// so use Dp to cache the subproblem T.C->O(M*N)  S.C->O(M*N)+recursive O(N*M)
int helper(int m,int n,int i,int j,vector<vector<int>> &dp){
    if(i==m-1&&j==n-1) return 1;
    if(i>=m||j>=n)return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
       return dp[i][j]=helper(m,n,i,j+1,dp)+helper(m,n,i+1,j,dp);
}

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>>dp(m,vector<int>(n,-1));   
    return  helper(m,n,0,0,dp);
}

/*
Use Combination of steps
number of downward step=M-1
number of Upward step=N-1
total steps=M+N-2
solution would be either put N-1 up in M+N-2 (M+N-2)C(N-1)
 or put M-1 up in M+N-2 (M+N-2)C(M-1) combination
combination trick
NCr
int res=1;
for(int i=1;i<=r;i++){
    res=(res*(N-r+i)/i)
}
e.g 10C3-->  10*9*8/3*2*1
*/
// ??Code
// Method 3
int N=n+m-2;
int r=m-1;
double res=1;
for(int i=1;i<=r;i++){
    res=res*(N-r+i)/i;
}
return (int)res;