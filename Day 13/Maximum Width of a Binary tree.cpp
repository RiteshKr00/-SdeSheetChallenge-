//Dont include Null Node
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)
        return 0;
    int m=0;
    queue<TreeNode<int>* >q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        m=max(m,sz);
        for(int i=0;i<sz;i++){
            TreeNode<int> *temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return m;
}
//Include Null Nodes also
int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long >> q;
        q.push({root,0});
        int l,r,m=INT_MIN;
        while(!q.empty()){
            int n=q.size();            
            int prev=q.front().second;           
            for(int i=0;i<n;i++){
                auto temp=q.front();
            q.pop();
                 TreeNode* node=temp.first;
            unsigned long long cur=temp.second;
                if(i==0)
                    l=cur;
                if(i==n-1)
                    r=cur;cout<<r<<" "<<l<<endl;
                if(node->left)
                    q.push({node->left,2*(cur-prev)});
                if(node->right)
                    q.push({node->right,2*(cur-prev)+1});
            }
            //calculate the maximum 
            m=max(m,r-l+1);
            
        }
        return m;
    }
    // we mark each level to start from 1 and go upto some digit
    // to do that we use 2(cur-prev) and 2(cur-prev)+1 to store the next level index
    // here prev is minm number of this level 