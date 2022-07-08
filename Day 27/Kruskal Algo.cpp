#include<bits/stdc++.h>
// T.C->O(MlogM)+O(M*4*alpha) i.e sort + m times disjointset operation(find+union)
//  S.C-> O(M)+O(N)+O(N)
int find(vector<int>&par,int node){
    if(node==par[node])
        return node;
    return par[node]=find(par,node);    
}
void un(vector<int>&par,vector<int>&rank,int node1,int node2){
    int u=find(par,node1);
    int v=find(par,node2);
     cout<<u<<" "<<v<<endl;
    if(rank[u]<rank[v])
        par[u]=v;
    else if(rank[u]>rank[v])
        par[v]=u;
    else
    {
        par[v]=u;
        rank[u]++;
    }
    cout<<par[u]<<par[v]<<rank[u]<<rank[v]<<endl;
}


int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    //union find
    int ans=0;
    sort(graph.begin(),graph.end(),[](vector<int>a,vector<int>b){return a[2]<b[2];});
    //create disjoint set
    vector<int>par(n+1);
    vector<int>rank(n+1,0);
    for(int i=1;i<=n;i++){
        par[i]=i;
    } 
    for(int i=0;i<graph.size();i++){
        int u=graph[i][0];
        int v=graph[i][1];
        int weight=graph[i][2];
        cout<<u<<"->"<<v<<" "<<weight<<endl;
    }
    for(int i=0;i<graph.size();i++){
        int u=graph[i][0];
        int v=graph[i][1];
        int weight=graph[i][2];
         if(find(par,u)!=find(par,v)){
             ans+=weight;
             cout<<ans<<endl;
                un(par,rank,u,v);
         }
    }       
    return ans;
}

//above code giving err dont know why so subnmitted this
int findPar(int u,vector<int> &par){
    if(u == par[u]){
        return u;
    }
    return par[u] = findPar(par[u],par);
}
	
int union_(int u, int v, vector<int> &rank,vector<int> &par){
    if(rank[u]<rank[v]){
        par[u] = v;
    }else if(rank[v]<rank[u]){
        par[v] = u;
    }else{
        par[v] = u;
        rank[u]++;
    }
}
	
bool comp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    sort(graph.begin(),graph.end(),comp);
    int cost = 0;
    vector<int> par(n+1),rank(n+1,0);
    for(int i=1;i<par.size();++i) par[i] = i;
    
    for(auto i:graph){
        if(findPar(i[0],par)!=findPar(i[1],par)){
            cost+=i[2];
            union_(findPar(i[0],par),findPar(i[1],par),rank,par);
        }
    }
    
    return cost;
    
}
