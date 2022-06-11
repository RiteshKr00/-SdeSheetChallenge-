//Note recursive soln same as unboubded knapsck or coinchange
//length of rod become maximum value and value array correspond to  coin array
//recursive code but length is decided by index value
int cutRod(int price[], int index, int n,vector<vector<int> >& dp)
{
    // base case
    if (index == 0) {
        return 0
    }
    if (dp[index][n] != -1)
        return dp[index][n];
        if(index+1<=n){
            return dp[index][n]=max(cutRod(price, index - 1, n,dp),price[index]
              + cutRod(price, index, n - rod_length,dp));
        }
        else
        return dp[index][n]=cutRod(price, index - 1, n,dp);    
}
//recursive similar as Unbounded knapsack but with given length array
int fn(int price[], int length[],int Max_len, int n)
{   
    if (n == 0 || Max_len == 0)
        return 0;

    if (length[n - 1] <= Max_len)
    {
        t[n][Max_len]= max(price[n - 1]+ fn(price, length,Max_len - length[n - 1], n),fn(price, length, Max_len, n - 1));
    }
    else
    {
        t[n][Max_len]= fn(price, length,Max_len, n - 1);
    }
    return t[n][Max_len];
}
//My code
//space optimized I
// here dp[i] denotes the max values obtained from a rod of length i  
 vector<int>dp(n+1,0);
        for(int i=0;i<=n;i++){//Rod length 
            for(int j=1;j<n;j++){//cut length
                if(i>=j){
                    dp[i]=max(dp[i],price[j-1]+dp[i-j]);
                }
            }
        }
return dp[n];

//space optimized 2
int val[n+1];val[0]=0;        
        for(int i=1;i<=n;i++){
            int  maxi=INT_MIN;
            for(int j=0;j<i;j++)
            maxi=max(maxi,price[j]+val[i-j-1]);
            val[i]=maxi;
            
        }        
return val[n];
