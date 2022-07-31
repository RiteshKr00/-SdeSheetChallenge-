int search(int* arr, int n, int key) {
    // Write your code here.
    int i=0,j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[i]<=arr[mid]){
            if(key<arr[mid]&&key>=arr[i])
                j=mid-1;
            else
                i=mid+1;
        }
        else{
            if(key>arr[mid]&&key<=arr[j])
                i=mid+1;
            else{
                j=mid-1;
            }
        }
    }
    
    return -1;
}