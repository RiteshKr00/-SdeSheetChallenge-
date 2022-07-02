/************************************************************
Main concept is to convert to string and retain the actual tree again from string
 use a preorder traversal and queue.

 # preorder traversal:1,2,x,x,3,4,x,x,5,x,x
 Now if we were to serialize it by using null as x and 1 as string characters this how it would become
 string data = 12xx34xx5xx
 12 can be seen as 1 or 12 and many complications would arise due to this.
 Thus we will try to use a delimiter (i.e commas (',')) to tackle this problem.
 string data = "1,2,x,x,3,4,x,x,5,x,x".

 # Okay we have finished with serialization.
 Now how do we deserialize string data = "1,2,x,x,3,4,x,x,5,x,x".
 We can just go through the data stream and be like if till comma or end of string make a new node out of that.
 This would be a very tedious process and may result in incorrect answers.
 We will try to use a data structure to solve this->Queue.

 queue is used because we process data left to right and do a preorder traversal

 

************************************************************/

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(!root)
        return "X,";
    return to_string(root->data)+","+serializeTree(root->left)+serializeTree(root->right);
    

}
TreeNode<int>* helper(queue<string>&q){
    string x=q.front();
    q.pop();
    if(x=="X")
        return NULL;    
    TreeNode<int>* root=new TreeNode<int>(stoi(x));
    root->left=helper(q);
    root->right=helper(q);
    return root;
    
}


TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    //extract each string and store it in queue in preorder
 queue<string>q;
    string s;
    for(int i=0;i<serialized.length();i++){
        if(serialized[i]==','){
            q.push(s);
            s="";
            continue;
        }
        s+=serialized[i];
    }
    return helper(q);
}

