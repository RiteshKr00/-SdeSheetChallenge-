#include <bits/stdc++.h> 
/****************************************************************

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(!head||K==0)
        return head;
    LinkedListNode<int>* x= new LinkedListNode<int>(0);
    x->next=head;
    LinkedListNode<int> *t=x,*s=x;
    int i=0;
    while(i++<K){
        t=t->next;
    }
    while(t->next){
        t=t->next;
        s=s->next;
    }
    LinkedListNode<int> *temp=s->next;
    s->next=temp->next;
    delete temp;
    return x->next;
    
}