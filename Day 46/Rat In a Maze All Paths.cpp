//Recursion+Back tracking

#include<bits/stdc++.h>
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void helper(vector<vector<int> > &maze,vector<vector<int> > &vis,int i,int j,int n,vector<vector<int> > &res){
//base case
    vis[i][j]=1;
    if(i==n-1&&j==n-1){
        vector<int >temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(vis[i][j]);
            }
        }
        res.push_back(temp);
        vis[i][j]=0;
        return;
    }
    //check all possibilities
    for(int d=0;d<4;d++){
        int row=i+dx[d],col=j+dy[d];
        if(row>=0&&row<n&&col>=0&&col<n&&vis[row][col]==0&&maze[row][col]==1){
            helper(maze,vis,row,col,n,res);            
        }               
    }
    vis[i][j]=0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int> > ans;
    vector<vector<int>>visited(n,vector<int>(n,0));
    
    helper(maze,visited,0,0,n,ans);    
    
    return ans;
}