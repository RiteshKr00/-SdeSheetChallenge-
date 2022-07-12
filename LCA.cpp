/************************************************************

    if both branch return something then current node is ancestor
    otherwise
    return the node returned by branch

************************************************************/
TreeNode<int> *helper(TreeNode<int> *root, int x, int y){
    if(!root)
        return NULL;
    if(root->data==x||root->data==y)
        return root;
      TreeNode<int> * l=helper(root->left,x,y);
        TreeNode<int> * r=helper(root->right,x,y);
    if(l&&r)
        return root;
    if(l)
        return l;
    if(r)
        return r;
    return NULL;
   
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return helper(root,x,y)->data;
    
    
}