T.C->O( H)  S.C-> O(1)

void inorder_predecessor(BinaryTreeNode<int>* root,int &pred, int key)
{
    while(root!=NULL)
    {
        if(root->data<key)
        {
            pred=root->data;
            root=root->right;
        }
        else if(root->data>=key)
        {
            root=root->left;
        }
    }
}
void inorder_successor(BinaryTreeNode<int>* root,int &succ, int key)
{
    while(root!=NULL)
    {
        if(root->data>key)
        {
            succ=root->data;
            root=root->left;
        }
        else if(root->data<=key)
        {
            root=root->right;
        }
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.

    int pred=-1;
    int succ=-1;
    
    inorder_predecessor(root,pred,key);
    inorder_successor(root,succ,key);
    
    pair<int,int>ans= {pred,succ};
    return ans;
}
/*
Predecessor
just travese the tree and 
#whenever we encounter a number less than key Store it in answer 
#but check if a number still exist which is greater then current but less than key ->
#it will be on right side of current
# if number is greater than equal to key than we move left side of current Node to
 get a value less than key


 similarly for suCCESSOR
 just reverse the condition
*/