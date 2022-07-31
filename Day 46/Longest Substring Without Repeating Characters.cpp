// we have to find the substring which is contagious
// so we use a set to store the element which has been already visited
// and traverse further and check if new char is not in set then we calculate the current distance from the ffirst element where no repetion occured.

// i=0,j=0
// acbghbef
// ->i=0 j=5
// then we will delete element one by at i untill the element at j is not in set
//  i=0                                     i=2
// acbghbef->cbghbef->bghbef->ghbef

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int i=0,j=0,n=input.length();
    set<char>s;
    int res=0;
    while(i<n&&j<n){
        if(s.find(input[j])==s.end()){            
            s.insert(input[j++]);
            res=max(res,j-i);
        }
        else{
            s.erase(input[i++]);
        }        
    }
    
    return res;
}