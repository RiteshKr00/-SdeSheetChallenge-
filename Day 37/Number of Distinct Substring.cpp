#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    //  Write your code here.
    unordered_set<string>s;
    int n=word.size();
    for(int i=0;i<n;i++){
        string temp;
        for(int j=i;j<n;j++){
            temp.push_back(word[j]);
            s.insert(temp);
        }
    }
    
    return s.size();
     
}
// T.C->O(N^2)&& S.C->O(N)
// Space Optimization using Trie Data Structure 
// (when we just need count of distinct substrings)
// The above approaches makes use of hashing which may lead to memory limit
//  exceeded (MLE) in case of very large strings. The approximate space complexity 
//  of them is around O(n^3) as there can be n(n+1)/2 substrings which is around O(n^2) 
//  and each substring can be at least of 1 length or n length

//IMplement using Trie data structure