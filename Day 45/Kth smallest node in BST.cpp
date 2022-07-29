/************************************************************

    Recursive Solution

************************************************************/
void h(TreeNode<int> *root, int &k,int &ans){
     if(!root)
         return;
    h(root->left,k,ans);
    k--;
    if(k==0)
        ans=root->data;
     h(root->right,k,ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    if(!root)
        return -1;
    int ans=0;
    h(root,k,ans);
    return ans;
}