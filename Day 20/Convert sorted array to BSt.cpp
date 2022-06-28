/************************************************************
 1)  Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.
          T.C->O(n)

************************************************************/
TreeNode<int>* fn(vector<int> &arr, int start,int end){
    if(start>end)
        return NULL;
    int mid=start+(end-start)/2;
    
    TreeNode<int>* t=new TreeNode<int>(arr[mid]);
    t->left=fn(arr,start,mid-1);
    t->right=fn(arr,mid+1,end);
    return t;
}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return fn(arr,0,n-1);
     
    
}