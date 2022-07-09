/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
//gives TLE  T.C->O(N^2)<-S.C
int findCelebrity(int n) {
 	// Write your code here.
    vector<vector<int>>v(n,vector<int>(n,-1));
    vector<int>poss;
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(knows(i,j))
              {  
                v[i][j]=1;
                flag=false;
            }
            else
                v[i][j]=0;
        }
        if(flag)
        {
            poss.push_back(i);
//           
        }
    }
    for(int i=0;i<poss.size();i++){
          bool flag2=true;
            for(int k=0;k<n;k++)
            {
                if(poss[i]==k)
                    continue;
                if(v[k][poss[i]]!=1){
                    flag2=false;
                }
            }
            if(flag2){
                return poss[i];
            }
    }
    
    return -1;
}
//using Degree : Gives TLE
int findCelebrity(int n) {
 	// Write your code here.
     vector<int>indegree(n,0),outdegree(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(knows(i,j))
              {  
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==n-1&&outdegree[i]==0)
            return i;
    }
    return -1;
}
//
// T.c->O(N),S.C->O(1)
int findCelebrity(int n) {
 	//we use logic if a->b discard aotherwise discard b
//     so we start from 0 and try to go to 1 and we can then discard  0 otherwise discard b; in this way no of possible candidates for celibrity are reduces
//   e.g 0->1  either 0 or 1 discarded store the not discarded in a variable x
//     Now try to go to 2 from x if x->2 discard x otherwise 2. so x will be updated with either 2 or previous value
    //IN this way goes till n-1 node and at last we have x as possible candidate
      int x=0;
    for(int i=1;i<n;i++){
        if(knows(x,i))
            x=i;
    }
//     Now x must be know by all and not know any body
    for(int i=0;i<n;i++){
        if(i!=x&&(!knows(i,x)||knows(x,i)))
            return -1;
    }
    return x;
}