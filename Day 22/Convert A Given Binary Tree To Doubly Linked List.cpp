/*************************************************************
 1. basic is to use a pointer  prev to point  just prev node in INorder fshion
 2.connect current Node->left->prev ofj every NOde
 and simultaneously  prev->right =root(current)
 and update prev=current Node every time INorder
 Note:
 To point to address either use (TreeNode** head) or(TreeNode* &head) in parameter
 of function

*************************************************************/
void helper(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &head,BinaryTreeNode<int>* &prev){
     if(!root)
        return ;
//     static BinaryTreeNode<int>* prev=NULL;
    //left 
    helper(root->left,head,prev);
    //processing
    //first node i.e leftmost element of inorder
    if(prev==NULL){
        head=root;
    }
    else{
         //link prev and current
        root->left=prev;
        prev->right=root;        
    }
    //update prev
        prev=root;
    //right
    helper(root->right,head,prev);  
}



BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    
     BinaryTreeNode<int>* head=NULL,*prev=NULL;
        helper(root,head,prev);
     return head;
    
}