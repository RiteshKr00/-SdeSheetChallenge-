bool helper(BinaryTreeNode<int>* l,BinaryTreeNode<int>* r){
    if(r==NULL||l==NULL)
        return r==l;
    return (r->data==l->data&&helper(l->left,r->right)&&helper(l->right,r->left));
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.  
    return helper(root,root);
}