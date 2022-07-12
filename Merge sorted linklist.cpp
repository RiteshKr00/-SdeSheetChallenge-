#include <bits/stdc++.h> 
/************************************************************
case : when a is empty /\ when b is empty /\ when a >b  /\ a<b

M1:
using dummy node i.e creating new list one by one comparing both list node
M2: using recursion T.C->O( O(m+n)



************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* ans=new Node<int>(-1);
    Node<int>* t=ans;
    while(first&&second){
        if(first->data<second->data){
            t->next=first;
            first=first->next;
            t=t->next;
        }else{
            t->next=second;
            second=second->next;
            t=t->next;
        }
    }
    if(first){
        t->next=first;
    }
    else
        t->next=second;
    return ans->next;
}
//Recursive version
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* ans=NULL;
    if(first==NULL)
    return second;
    else if(second==NULL)
        return first;
    else if(first->data<second->data){
        ans=first;
        ans->next=sortTwoLists(first->next,second);
    }
    else {
        ans=second;
        ans->next=sortTwoLists(first,second->next);
    }
    return ans;
}
