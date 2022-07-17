#include<bits/stdc++.h>
/************************************************************
"average" O(1) time. O(H)Space
//recursion using stack (INORDER)
************************************************************/

class BSTiterator
{    private:
    stack<TreeNode<int>*>s;
 public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
         helper(root);
    }

    int next()
    {
        // write your code here
         TreeNode<int>* x=s.top();
        s.pop();
        if(x->right!=NULL)
         helper(x->right);
        return x->data;
        
    }

    bool hasNext()
    {
        // write your code here
         return !s.empty(); 
    }
   
    void helper(TreeNode<int>* root){
         TreeNode<int>* t=root;
        while(t!=NULL){
            s.push(t);
            t=t->left;
        }
    }
};

