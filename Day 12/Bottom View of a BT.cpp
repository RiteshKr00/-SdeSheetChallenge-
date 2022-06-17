/*************************************************************
 T.C->O(N) S.C->O(n) nuber of Nodes
*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    queue<pair<BinaryTreeNode<int>*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        mp[0]=root->data;
        while(!q.empty()){
            BinaryTreeNode<int>* x=q.front().first;
            int y=q.front().second;
        q.pop();
        
        if(x->left){
            q.push({x->left,y-1});
            mp[y-1]=x->left->data;
        }
            
        if(x->right){
            q.push({x->right,y+1});
            mp[y+1]=x->right->data;
        }   
        
        }
        vector<int>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }  
        return ans;
    
}
