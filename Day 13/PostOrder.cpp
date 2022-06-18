void postorder(TreeNode *root,vector<int> &ans){
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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
      vector<int> ans;
    postorder(root,ans);
    return ans; 
}