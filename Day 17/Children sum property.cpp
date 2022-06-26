/*************************************************************

  in some case Child Sum become less and we cannot make parent from them
  So intution is
  While going down increase the child value Or more accurately equate both left and right child 
  to its parent value;
  ANd when coming Back make current root->value equal to (left + right )child value 
T.C->O(N) S.C->O(Na)
*************************************************************/

int rtl(BinaryTreeNode < int > * root){
    if(!root)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return root->data;
    int sum=0;
    if(root->left)
        sum+=root->left->data;
    if(root->right)
        sum+=root->right->data;
    
    if(root->data>sum){
        if(root->left)
        root->left->data=root->data;
    if(root->right)
        root->right->data=root->data;
    }
    return  root->data=rtl(root->left)+rtl(root->right);

}

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    //root to leaf
    rtl(root);
       
    
}  