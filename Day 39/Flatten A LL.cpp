#include <bits/stdc++.h> 
/****************************************************************

*****************************************************************/
//gives TLE if we not inlink next pointer i.e     t->next=NULL;
Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    Node* ans=new Node(-1);
    Node* t=ans;
    while(first&&second){
        if(first->data<second->data){
            t->child=first;
            first=first->child;
            t=t->child;
        }else{
            t->child=second;
            second=second->child;
            t=t->child;
        }
        t->next=NULL;//unlink next pointer
    }
    if(first){
        t->child=first;
    }
    else
        t->child=second;
    return ans->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head==NULL||head->next==NULL)
        return head;
    head->next=flattenLinkedList(head->next);   
    head=sortTwoLists(head, head->next);
    return head;
    
}
