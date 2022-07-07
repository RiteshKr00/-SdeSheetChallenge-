bool possible(vector<vector<int>>&ans,int x,int y)
{
    int n=ans.size();
    for(int i=0;i<x;i++)
    {
        if(ans[i][y]==1)
            return false;
    }
    for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
    {
        if(ans[i][j]==1)
            return false;
    }
    for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++)
    {
        if(ans[i][j]==1)
            return false;
    }
    return true;    
}

bool helper(vector<vector<int>>&output,vector<vector<int>>&ans,int n,int i=0)
{
    if(i>=n)
    {
        vector<int>temp;
        for(auto i:ans)
            for(auto j:i)
                temp.push_back(j);
        output.push_back(temp);
        return false;
    }
        
    for(int j=0;j<n;j++)
    {
          if(possible(ans,i,j))
          {
              ans[i][j]=1;
              bool b=helper(output,ans,n,i+1);
              if(b==false)
                  ans[i][j]=0;
              else
                  return true;
          }
    }
    return false;
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>ans(n,vector<int>(n,0));
    vector<vector<int>>output;
    helper(output,ans,n);
    return output;
}
//leetcode 's using Hash
class Solution {
public: 
    void fill(vector<vector<string>>&ans,vector<string> v,int col,int n,vector<int> left,vector<int>upper,vector<int>down){
        //base case
        if(col==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(left[i]!=1&&upper[n-1+(col-i)]!=1&&down[i+col]!=1){
                v[i][col]='Q';
                left[i]=1;
                upper[n-1+(col-i)]=1;
                down[i+col]=1;
                fill(ans,v,col+1,n,left,upper,down);
                v[i][col]='.';
                left[i]=0;
                upper[n-1+(col-i)]=0;
                down[i+col]=0;              
            }
        }
        
        
    }    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>v(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            v[i]=s;
        }
        vector<int>left(n,0),upper(2*n-1,0),down(2*n-1,0);
        
        fill(ans,v,0,n,left,upper,down);  
        return ans;
        
    }
};