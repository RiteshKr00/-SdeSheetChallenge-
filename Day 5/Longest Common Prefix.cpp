/*METHOD
1.sort- It ensures that length of common prefix will be minimum of length of first or last string of array 
after sorting if I contradict-(answer)_>that string with more or less common prefix will be either at first 
 or last place

2.character by character Matching
T.C->O(M*N) Auxillary S.C->O(M) 
*/

// MyCode Divide and conquer
// T.C->O(M*N) Auxillary S.C->O(MlogN) 
// logN because array is divided in every level
// N = Number of strings
// M = Length of the largest string string
class Solution {
public:
    string Common(vector<string>& strs,int s,int e){
        if(e-s==0)
            return strs[e];
        string x=Common(strs,s,s+(e-s)/2);
        string y=Common(strs,s+(e-s)/2+1,e);
        int len=min(x.length(),y.length());
        string z="";
        for(int i=0;i<len;i++){
            if(x[i]==y[i])
            z.push_back(x[i]);
            else 
                break;
        }        
        return z;        
    }        
    string longestCommonPrefix(vector<string>& strs) {
        
        return Common(strs,0,strs.size()-1);
        
    }
};