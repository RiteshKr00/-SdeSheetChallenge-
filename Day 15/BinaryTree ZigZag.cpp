/*************************************************************
Use two stack to get the next level order
and use a variable order to change the order of traversal
T.C->O(N)number of Nodes
S.C->O(N)Maximum number of nodes stored in nodes at a time

*************************************************************/
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    int order=-1;
    vector<int>ans;
    stack<BinaryTreeNode<int> *>s1,s2;
    if(root==NULL)
        return ans;
    s1.push(root);
    while(!s1.empty()){    
//         cout<<order;
        while(!s1.empty()){
        BinaryTreeNode<int> * temp=s1.top();
        s1.pop();
        ans.push_back(temp->data);  
//             cout<<" "<<temp->data<<" ";
            if(order==-1){
                if(temp->left)
                    s2.push(temp->left);
                if(temp->right)
                    s2.push(temp->right);                
            }
            else if(order==1){
                 if(temp->right)
                    s2.push(temp->right);  
                if(temp->left)
                    s2.push(temp->left);               
            }
        }    
//         cout<<endl;
            order*=-1;
            swap(s1,s2);
    }
    return ans;
}
