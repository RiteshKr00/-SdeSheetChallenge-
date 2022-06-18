
/*************************************************************
 
    T.C->O(n)  Auxilary S.C-> O(n)

 n=height(worst case)
*************************************************************/
int isBalanced(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    int lh=isBalanced(root->left);
    if(lh==-1)return -1;
    int rh=isBalanced(root->right);
      if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    return 1+max(lh,rh);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(isBalanced(root)==-1)
        return false;
    return true;
}