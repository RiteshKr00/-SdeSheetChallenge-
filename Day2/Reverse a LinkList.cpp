#include <bits/stdc++.h> 
/****************************************************************
    we use three pointer prev cur and n=next to store the address of Nodes
    prev cur next
    /    / /
   NULL   1   2  3  4  5 
   and do these operation untill current reaches the last NOde then return cur
           { n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;}
*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head==NULL)
            return head;
        LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *cur=head;
    LinkedListNode<int> *n=head;
        while(cur->next!=NULL){
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
        }
        cur->next=prev;
        return cur;
}