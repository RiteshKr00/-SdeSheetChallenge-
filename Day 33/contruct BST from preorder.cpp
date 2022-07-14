#include<bits/stdc++.h>
/*************************************************************
T.C->O(N);
S.C->O(N);

use a bound to check whether it is permissible there or not
#we can solve it using only right bound
\//base case when preorder exhausted or element is out of bounds
*for root->left use root->val as bound
*for root->right use the bound passed on from parent

*************************************************************/
TreeNode<int>*  helper(vector<int>& preorder,int &id,int bound){
        if(id==preorder.size()||preorder[id]>bound)
            return NULL;
    TreeNode<int>*  root=new TreeNode<int>(preorder[id++]);

        root->left=helper(preorder,id,root->data);
   
         root->right=helper(preorder,id,bound);
    
        
        return root;
        
    }
 
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int id=0;
    return helper(preOrder,id,INT_MAX);
}