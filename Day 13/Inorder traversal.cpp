/*
T.C->O(heighti.e logN)  S.C-> O(height) stack
*/
void inorder(TreeNode *root,vector<int> &ans){
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

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inorder(root,ans);
    return ans;    
}