/*************************************************************
 Define Range at start and modify(according to condition) min and max and at each node 
 check if current node ->data is between the range.if yes return true;
 otherwise false.
 T.C->O(N),Auxillary S.C->O(1)


*************************************************************/
int util(BinaryTreeNode<int> *root,int mi,int ma){
    if(!root)
        return 1;
    if(root->data<mi||root->data>ma)
        return 0;
    return (util(root->left,mi,root->data)&&util(root->right,root->data,ma));
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return util(root,INT_MIN,INT_MAX);
}
//Method 2
//use inorder traversal  and a prev node to store prev value
bool isBST(node* root)
{
    static node *prev = NULL;
     
    // traverse the tree in inorder fashion
    // and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
        return false;
 
        // Allows only distinct valued nodes
        if (prev != NULL &&
            root->data <= prev->data)
        return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}