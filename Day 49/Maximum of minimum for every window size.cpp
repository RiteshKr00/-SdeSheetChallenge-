// M1:Brute force
// T.C->O(N^3)
for(int i=1--->N(EachwindowSize)){
int maxmof_current_WIndowSize=INT_MIN;

for(int j=0;j<n-k;j++){
    int MINMof_current_WIndow=INT_MAX;
    for(int k=1---->i){
        //update the min
        if(arr[k+j]<min)
        min=arr[k+j]
    }
    updatehere MAXOFMIN

}
}
//CODE of the loop:
for (int k = 1; k <= n; k++) {
        // Initialize max of min for
        // current window size k
        int maxOfMin = INT_MIN;
 
        // Traverse through all windows
        // of current size k
        for (int i = 0; i <= n - k; i++) {
            // Find minimum of current window
            int min = arr[i];
            for (int j = 1; j < k; j++) {
                if (arr[i + j] < min)
                    min = arr[i + j];
            }
 
            // Update maxOfMin if required
            if (min > maxOfMin)
                maxOfMin = min;
        }
}

Method 2:
// optimizing the inner loop 
//Similar to Maximum sliding window (there we used deque)
/*we maintain a deque in increasing order
    ->1st element is minimum of current window with given size
    ->we one by one move forward and keep removing those element which become out of bounds
        or a better option exist than at front(them);

T.C->O(N^2) S.C->O(K->where k vary==size)

*/
//code  wrong to be corrected
#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    //maintain increasing order
    deque<pair<int,int>>dq;
    vector<int> ans;
    for(int i=1;i<=n;i++){ 
        int maxm=INT_MIN;
        for(int k=0;k<i-1;k++){
            if(!dq.empty()){
                if(a[k]>=dq.front().first){
                   dq.push_back({a[k],k});
                }
                else if(a[k]<dq.front().first){
                    while(!dq.empty())dq.pop_front();
                    dq.push_back({a[k],k});
                }
            }
            else{
                dq.push_back({a[k],k});
            }
        }
        for(int j=i-1;j<n;j++){
            //remove out of bound element
            while(!dq.empty()&&dq.front().second<=j-i){
                    dq.pop_front();
            }
            if(!dq.empty()){
                if(a[j]>=dq.front().first){
                    dq.push_back({a[j],j});
                }
                else if(a[j]<dq.front().first){
                    while(!dq.empty())dq.pop_front();
                    dq.push_back({a[j],j});
                }
            }
            else{
                dq.push_back({a[j],j});
            }
//             cout<<dq.front().first<<" ";
            maxm=max(maxm,dq.front().first);            
        }
//         cout<<"\n max among above is "<<maxm<<endl;
        ans.push_back(maxm);
        dq.clear();
    }
    return ans;
}




// Method 3:Base on NGE
// T.C->O(N)
#include<stack>
vector<int> nextSmaller(vector<int> &a)
{
    int n=a.size();
    vector<int> v(n,n);
    stack<pair<int,int>> s;
    s.push({a[n-1],n-1});
    
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() and s.top().first>=a[i])
            s.pop();
        
        if(!s.empty())
            v[i]=s.top().second;
        s.push({a[i],i});
    }
    
    return v;
}
vector<int> prevSmaller(vector<int> &a)
{
    int n=a.size();
    vector<int> v(n,-1);
    stack<pair<int,int>> s;
    s.push({a[0],0});
    
    for(int i=1;i<n;i++)
    {
        while(!s.empty() and s.top().first>=a[i])
            s.pop();
        
        if(!s.empty())
            v[i]=s.top().second;
        s.push({a[i],i});
    }
    
    return v;
}
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ns=nextSmaller(a);
    vector<int> ps=prevSmaller(a);
    
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++)
    {
        int l=(ns[i]-ps[i]-1)-1;  
        if(a[i]>ans[l])
            ans[l]=a[i];
    }
    for(int i=n-2;i>=0;i--)
        if(ans[i]<ans[i+1])
            ans[i]=ans[i+1];
    return ans;
}