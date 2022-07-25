#include <bits/stdc++.h> 
/****************************************************************


*****************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    Node* t1=head1,*t2=head2;
    Node* temp1=new Node(0);
    Node *temp=temp1;
    int carry=0;
    while(t2!=NULL||t1!=NULL||carry!=0){
        int x=t1!=NULL?t1->data:0;
        int y=t2!=NULL?t2->data:0;
        int sum=(x+y+carry)%10;
        carry=(x+y+carry)/10;
        temp->next=new Node(sum);
        temp=temp->next;
        t1=t1!=NULL?t1->next:NULL;
        t2=t2!=NULL?t2->next:NULL;
    }
    return temp1->next;
    
}

//ADD TWO NUMBER LL 2
/****************************************************************
first equate two number by adding o in front
 then  now use recursion to dive to the end of both the lists and start addition 
 from the end.After each recursion ends, l1 and l2 will be waiting at the previous
  nodes, so an indirect reverse traversal is obtained without the use of a doubly
   linked list.The key is being able to pass carry from current recursive function
    to the previous recursive function, for which we can pass the reference variable
 carry to function calls so that the changes made to carry reflect through all the recursive calls made.

*****************************************************************/

class Solution {
public:
    ListNode* Add(ListNode* l1,ListNode* l2,int &carry){
    if(l1==NULL&&l2==NULL)
    return NULL;
    ListNode *n=new ListNode(0);
    n->next=Add(l1->next,l2->next,carry);
    n->val=(l1->val+l2->val+carry)%10;
    carry=(l1->val+l2->val+carry)/10; 
    return n;   
}



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1p=l1,*l2p=l2;
while(l1p!=NULL||l2p!=NULL){
    if(l1p==NULL){
        ListNode *n=new ListNode(0);
        n->next=l1;
        l1=n;
        l2p=l2p->next;
    }
    else if(l2p==NULL){
        ListNode *n=new ListNode(0);
        n->next=l2;
        l2=n;
        l1p=l1p->next;
    }
    else{
        l1p=l1p->next;
        l2p=l2p->next;
    }
}
int carry=0;
ListNode *dummy=new ListNode(0);
dummy->next=Add(l1,l2,carry);
if(carry){
    ListNode *n=new ListNode(carry);
    n->next =dummy->next;
    dummy->next=n;   
}
return dummy->next;
    }
};