/*
T.C->O(n)
logic:if there are no zero in array
maximum product will be either prefix or suffix i.e. then the subarray with maximum product must start with the first element or end with the last element
if zero is present Well, we can split the array into several smaller ones. 
That's to say, when the prefix product is 0, we start over and compute prefix product from the current element instead
*/
int solve(int n, vector<int> arr){
//CODE HERE 
int maxi=INT_MIN,cur=1;
for(int i=0;i<n;i++){
    cur*=arr[i];
    if(cur>maxi)
    maxi=cur;
    //if current is Zero
    if(cur==0){
        cur=1;
    }

}
cur=1;
for(int i=n-1;i>=0;i--){
    cur*=arr[i];
    if(cur>maxi)
    maxi=cur;
    if(cur==0){
        cur=1;
    }

}
return maxi;
}