/*
*solve in postorder manner.
*Make a structure to store the deails to be returned upward from wch node
//write base case
*if(root is null it will always bst of size 0)
min=INT_Max to make upper node comparable and updatable;
max=INT_MIN;

*go left and right andget detials

*Now for bst check whether (left.max<cur->val<right.min) if yes its a bst
update min=min(cur->data,left.min)//because if left tree is null then min will cur->data
similarly max=max(right.max,cur->data);

other wise 
* make min=INT_MIN so that further in upper part we cant compare and update fields
 on basis of that
because for bst in we compare right.min with cur val ans since it is min 
makes false the condition of bst(right.min(INT_MIN)>cur->data)
*similar
for max=INT_MAX;
*/
struct Details{
    int min_el,max_el,max_size;
    
    Details(int min_el,int max_el,int max_size){
        this->min_el=min_el;
        this->max_el=max_el;
        this->max_size=max_size;
    }
};

Details helper(TreeNode<int>*root){
    //base case
    if(!root)
        return Details(INT_MAX,INT_MIN,0);
    Details l=helper(root->left);
        Details r=helper(root->right);
    //if bst
    if(l.max_el<root->data&&r.min_el>root->data){
        return Details(min(l.min_el,root->data),max(r.max_el,root->data),1+(l.max_size+r.max_size));
    };
    
  return Details(INT_MIN,INT_MAX,max(l.max_size,r.max_size));
}

int largestBST(TreeNode<int>* root) 
{
    return helper(root).max_size;
}
