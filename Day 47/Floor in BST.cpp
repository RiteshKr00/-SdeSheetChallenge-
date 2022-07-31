/************************************************************
Similar to  find a number in BST

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(!root)
        return -1;
    int res;
    while(root){
        if(root->val<=X){
            res=root->val;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return res;
}