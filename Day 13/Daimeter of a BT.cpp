/************************************************************

 T.C->O(height)i.e n in case of skew matrix
modify height problem to store the maxm length possible at each node 

************************************************************/
int diameter(TreeNode<int>* root,int &ans){
    if(root==NULL)
        return 0;
    int lh=diameter(root->left,ans);
    
    int rh=diameter(root->right,ans);
      ans=max(ans,lh+rh);
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int ans=-1;
    diameter(root,ans);
    return ans;
    
}
