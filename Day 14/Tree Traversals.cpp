/************************************************************

************************************************************/
void inorder(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL)
        return;
    if(root->left){
        inorder(root->left,ans);
    }
    ans.push_back(root->data);
    if(root->right){
        inorder(root->right,ans);
    }
}
void postorder(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL)
        return;    
    if(root->left){
        postorder(root->left,ans);
    }    
    if(root->right){
        postorder(root->right,ans);
    }
    ans.push_back(root->data);
}
void preorder(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL)
        return;
    ans.push_back(root->data);
    if(root->left){
        preorder(root->left,ans);
    }    
    if(root->right){
        preorder(root->right,ans);
    }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
     
    vector<int>v1,v2,v3;
    preorder(root,v2);
    inorder(root,v1);
    postorder(root,v3);
    vector<vector<int>>ans({v1,v2,v3});
    return ans; 
}