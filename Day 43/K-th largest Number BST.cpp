/*
Think of the Recursion.
go to right most node first.
then use k and keep subtracting k until k==0
pass k as a reference so that we simulate like we traversing from last to first
Time Complexity: O(n).IN worst case when k=n;
*/
void helper(TreeNode<int>* root, int &k,int &ans){
    if(!root||k<0)
        return ;
    helper(root->right,k,ans);
    k--;
    if(k==0){
        ans=root->data;
    }
    helper(root->left,k,ans);
    
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
   int ans=-1;
    helper(root,k,ans);
    return ans;   
}
