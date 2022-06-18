/************************************************************
we can use recursive as well as level order but recursive used less space (avrage)
we use a data structure to store the 1st element
and make use of ds length .we compare the level with ds.size
ans since the level start from zero we only push new encountered elemrent in ds when level == ds.size .
this ensures only first element is included.
Note:we maintain a maxLevel till now which is here maintained by ds size
************************************************************/
void left(TreeNode<int>* root,vector<int>&ans,int level){
    if(root==NULL)
        return ;
    if(level==ans.size())
        ans.push_back(root->data);
    left(root->left,ans,level+1); //      }   exchange these two lines and left become right
    left(root->right,ans,level+1);//      }   
    
}

vector<int> getLeftView(TreeNode<int> *root)
{
  vector<int> ans;
    left(root,ans,0);
    return ans;    
}