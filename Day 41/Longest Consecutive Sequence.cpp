// Gives TLE
T.C->O(N)    S.C->O(N)
#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
     set<int>s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    int maxi=INT_MIN;
//     for(auto it=s.begin();it!=s.end();it++){
//         if(s.find(*it-1)==s.end()){
//             cnt=1;
//             int x=*it;
//             while(s.find(x+1)!=s.end())
//              {   cnt++;x++;}
//             maxi=max(maxi,cnt);
//         }
//     }
    //now traversing the array
    for(int i=0;i<arr.size();i++){
        if(s.find(arr[i]-1)!=s.end())
            continue;
        else{
            int cnt=0;
            int x=arr[i];
            while(s.find(x)!=s.end()){
                cnt++;
                x++;
            }
            maxi=max(maxi,cnt);
        }
    }
    
    return maxi;
    
    
}
//same complexity but accepted
#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int N = arr.size();
        int len = 0, res = INT_MIN;
        if(N == 0)
            return 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < N; i++)
           mp[arr[i]]++;
        for(auto i : arr)
        {
            if(mp.find(i - 1) == mp.end())
            {
                int k = i;
                int len = 1;
                while(mp.find(k + 1) != mp.end())
                {
                    k++;
                    len++;
                }
                // cout<<k<<"len-- "<<i<<"    ";   
                res = max(res, len);
            }
        }
        return res > 0 ? res : 1;
    
}