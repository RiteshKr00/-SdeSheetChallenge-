/*
Basically here we have to find all the palindromic list so we use recursion+backtracking
to find all the possible list
//base condition
if we reaches some how last index of string after going through different  levels of recursion
we return the list i.e it is the ans.

T.C->O(N*2^N)  S.C->O(N) space used to store the recursion stack
*/
class Solution {
public:
    bool isPal(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j])
            {
                i++;j--;
            }
            else
                return false;
        }
        return true;
    }
        
void dfs(vector<vector<string>>& ans,vector<string>v,string s,int start){
        if(start==s.length())
            ans.push_back(v);
        for(int end=start;end<s.length();end++){
            if(isPal(s,start,end)){
                v.push_back(s.substr(start,end-start+1));
                dfs(ans,v,s,end+1);
                v.pop_back();
            }
        }
    }   
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        dfs(ans,current,s,0);
        return ans;
    }
};