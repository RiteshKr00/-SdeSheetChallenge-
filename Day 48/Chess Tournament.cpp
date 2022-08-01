/*
Similar to Book allocation and aggressive cow firs find the search Space
and check for feasible solution using binary Search
T.C->O(NlogN)

*/
 bool haveFocus(int focus,vector<int>p,int chessplayer){
int n=p.size();
    int CurChessPlayer=1;
    //Greedy approach to assign leftmost room to first
    int prevRoom=0;
    for(int i=1;i<n;i++){
        if(p[i]-p[prevRoom]>=focus){
            CurChessPlayer++;
            prevRoom=i;
        }
    }
    
    //if all player assigned room  return true
    if(CurChessPlayer>=chessplayer)
        return true;
    
    return false;
    

}



int chessTournament(vector<int> p , int n ,  int c){
	// Write your code here
    sort(p.begin(),p.end());
    //take low 0 aor any thing  bSearch automaticaly removes extra
    int res;
    int low=0;
    int high=p[n-1]-p[0];
    while(low<=high){
        int mid=low+(high-low)/2;
        if(haveFocus(mid,p,c)){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;
}