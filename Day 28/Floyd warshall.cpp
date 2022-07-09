// T.C->O(V^3)  S.C:O(V^2)
// find shortest distance between all pair 
// if any dist become -ve it means it has negative edge weight cycle

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
   vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    for(auto it: edges){
        dist[it[0]][it[1]] = it[2];
    }
    
    int i = 1;
    while(i <= n){
        dist[i][i] = 0;
        i++;
    } 
  //including in intermedite one by one for checkin shortest path
    for(int k=1;k<=n;k++){
        //source
        for(int i=1;i<=n;i++){
//             destination
            for(int j=1;j<=n;j++){
                if(dist[i][k]==1e9||dist[k][j]==1e9)
                    continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    return dist[src][dest];
    
}