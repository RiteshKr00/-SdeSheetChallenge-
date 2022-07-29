/************************************************************

   Similar to Successor with equal to condition

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int key){
    // Write your code here.
     int succ=-1;
    while(root!=NULL)
    {
        if(root->data==key)
            return root->data;        
        else if(root->data>key)
        {
            succ=root->data;
            root=root->left;
        }
        else if(root->data<key)
        {
            root=root->right;
        }
    }
    return succ;
}