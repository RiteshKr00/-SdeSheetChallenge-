/*
M1->store the inorder in array and use the two pointer to find the sum
#more efficent__>we can use Hash map to chek while traversing the tree
=>But both approach takes T.C-O(N) S.C->O(N)
M2:
1 We traverse BST in Normal Inorder and Reverse Inorder simultaneously.
2 In reverse inorder, we start from the rightmost node which is the maximum value node.
3 In normal inorder, we start from the left most node which is minimum value node.
4 We add sum of current nodes in both traversals and compare this sum with given target sum.
5 If the sum is same as target sum, we return true.
6 If the sum is more than target sum, we move to next node in reverse inorder traversal,
7 otherwise we move to next node in normal inorder traversal.
8 If any of the traversals is finished without finding a pair, we return false.

*/
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<stack>
typedef BinaryTreeNode<int> node;
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    stack<node*> inc,dec;
    node *f=root,*b=root;
    while((!inc.empty()||f)&&(!dec.empty()||b)){
//     store all left node in inc stack
        while(f){
            inc.push(f);
            f=f->left;
        }
        //similarly store right nodes
        while(b){
            dec.push(b);
            b=b->right;
        }
        //take two pointer to simulate the find sum in sorted array
        node *i=inc.top(),*j=dec.top();
        if(i->data+j->data==k)
            return true;
        if(i->data+j->data<k){
            //increase forward (i)value
            inc.pop();
            //go to right to increase the value of i
            f=i->right;
        }
        else{
            dec.pop();
            b=j->left;
        }
        
    }
    
    return false; 
    
    
}