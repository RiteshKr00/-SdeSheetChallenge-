/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
long long int helper(TreeNode<int> *root, long long int &ans){
    if(!root)
        return 0;
    long long int l=helper(root->left,ans);
    long long int r=helper(root->right,ans);
    //compare with current Node and with currentNode+one branch;
    long long int z=root->val;
    long long int x=max(z,z+max(l,r));
//     update max ans
     ans=max(ans,max(x,z+l+r));
    
    return x;
    
}
void leaves(TreeNode<int>* root,int &count){
        if(root==NULL)
            return;
        leaves(root->left,count);
        leaves(root->right,count);
        if(root->left==NULL && root->right==NULL)
               count++;
    }

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
     if(root==NULL)
            return -1;
       int count=0;
       leaves(root,count);
        if(count==0|| count==1)
            return -1;
//     if(root==NULL)
//         return -1;
    long long int ans=INT_MIN;
    helper(root,ans);
    return ans;
}