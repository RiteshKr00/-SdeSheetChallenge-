//Recursion
//Time Complexity: O(m^V) S.C:o(V)
bool isSafe(vector<vector<int>> &mat,vector<int> color,int n,int currentNode,int col){
    for(int i=0;i<n;i++){
        if(i!=currentNode&&mat[i][currentNode]==1&&color[i]==col)
            return false;
    }
    return true;
}


bool colorGraph(vector<vector<int>> &mat, int m,vector<int>& color,int n,int node){
    //base case
    if(node==n)
       return true;//means we hace coloured all nodes succesfully
//     //check for all adjacent nodes
//     for(int k=0;k<n;k++){
        
//     }
    //try to color the nodes with all m colors
    for(int i=1;i<=m;i++){
        if(isSafe(mat,color,n,node,i)){
            color[node]=i;
            //now recurse for next node and if that can be coloured return true; otherwise backtrack
            if(colorGraph(mat,m,color,n,node+1))
                return true;
            color[node]=0;            
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int>col(n,0);
    bool ans=colorGraph(mat,m,col,n,0);
    if(ans)
        return "YES";
    else
        return "NO";
    
}