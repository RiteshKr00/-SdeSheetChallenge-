/************************************************************
  
   
   
 ************************************************************/
 
 
 TreeNode<int>* build(vector<int>& postorder, vector<int>& inorder, int& rootIdx, int st, int end) {
        if (st>end)
            return NULL;
        // find the root idx from inorder
        int inidx=find(inorder.begin(),inorder.end(),postorder[rootIdx])-inorder.begin();
        
        rootIdx--;
        TreeNode<int>* newNode = new TreeNode<int>(inorder[inidx]);
        newNode->right = build(postorder, inorder, rootIdx, inidx+1, end);
        newNode->left = build(postorder, inorder, rootIdx, st, inidx-1);
        return newNode;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    int rootIdx = postOrder.size()-1;
        int n=inOrder.size();
        return build(postOrder, inOrder, rootIdx, 0, n-1);
}
