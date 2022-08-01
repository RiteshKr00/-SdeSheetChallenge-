#include<bits/stdc++.h>
//simple BFS or we can say recursion //pattern
int dx[8]={-1,1,-1,1,0,1,-1,0};
int dy[8]={-1,1,1,-1,1,0,0,-1};
void mark(int** arr, int n, int m,int i, int j,vector<vector<int>>&vis){
    if(i<0||j<0||i>n-1||j>m-1)
        return;    
    if(arr[i][j]==0||vis[i][j]==1)
        return;
//    cout<<"possible"<<i<<j<<endl;
        vis[i][j]=1;
        for(int k=0;k<8;k++){            
            int x=i+dx[k];
            int y=j+dy[k];
//             cout<<i<<
// " "<<j<<"new cordinate "<<x<<" "<<y<<endl;
            mark(arr,n,m,x,y,vis);
        }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    vector<vector<int>>vis(n,vector<int>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1&&vis[i][j]==0){
//                 cout<<"-------------"<<endl;
                ans++;
                mark(arr,n,m,i,j,vis);
            }
        }
    }
    return ans;
}
