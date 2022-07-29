// Find Pattern in String
// 1. Naive algo
// Time complexity worst case is O(m*(n-m+1);
// s = "AAAAAAAAAAAAAAAAAB";
// p = "AAAAB";
bool findPattern(string p, string s)
{
    // Write your code here.
    int n=p.length();
    int m=s.length();
    for(int i=0;i<=m-n;i++){
        int j;
        for(j=0;j<n;j++)
            if(s[i+j]!=p[j])
                break;
        if(j==n)
            return 1;
    }
    return 0;
}
//Knuth Morris Pratt) Pattern searching

#include<string>
#include<bits/stdc++.h>
//calculate lps
void find_lps(string p, int m, vector<int> &lps){
    int prevLps = 0;
    for(int i=1; i<m; i++){
        if(p[i] == p[prevLps]){
            lps[i] = prevLps+1;//put in lps array the length of max prefix
            prevLps++;
        }
        else if(prevLps == 0) lps[i] = 0;              
        else{
            //carefully analyze
            //Move prevLps backward to an element until which prevLps is having a prefix    
            prevLps = lps[prevLps-1]; 
            i--;
        }
    }
}

bool findPattern(string p, string s)
{
    int m = p.length();
    int n = s.length();
    vector<int> lps(m, 0);
    
    if(m == 0) return false;
    find_lps(p, m, lps);
    
    int i=0, j=0;
    while(i<n){
        if(s[i] == p[j]){
            i++, j++;
        }
        else{
            //tricky part
            if(j == 0) i++; 
            else j = lps[j-1];
        }
        if(j == m) return true;
    }
    
    return false;
}
