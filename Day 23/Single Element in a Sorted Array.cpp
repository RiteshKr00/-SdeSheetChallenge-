apply binary search on property that where should we move;
if(unique element is after the mid then mid=even and arr[mid]==arr[mid+1])else before;
or(unique element is after the mid then mid=odd and arr[mid]==arr[mid-1])else before;

int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int l=0,h=n-1;
int res;
while(l<=h){
    int  mid=l+(h-l)/2;
    if(l==h)
    {res=arr[l];
    break;}
    if(mid%2==0){
        if(arr[mid+1]==arr[mid])
        l=mid+2;
        else
        h=mid;
    }
    else{
        if(arr[mid-1]==arr[mid])
        l=mid+1;
        else
        h=mid-1;
    }
}

return res;
}
