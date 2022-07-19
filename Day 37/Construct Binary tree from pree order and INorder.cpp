/************************************************************

   Take care of boundary condition like
   1> if(l>r)
        return NULL;
   2>  while(id<r&&inorder[id]!=preorder[p])id++;

   3> pass preorder index as reference    

************************************************************/
TreeNode<int> *helper(vector<int> &inorder, vector<int> &preorder,int l,int r,int &p){
    if(l>r)
        return NULL;
    TreeNode<int>* root=new TreeNode<int>(preorder[p]);
    //find index of in inorder
    int id=l;
    while(id<r&&inorder[id]!=preorder[p])id++;
    
    p++;
    root->left=helper(inorder,preorder,l,id-1,p);
    root->right=helper(inorder,preorder,id+1,r,p);
    return root;
    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int p=0;
    return helper(inorder,preorder,0,inorder.size()-1,p);    
}