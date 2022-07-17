#include <bits/stdc++.h> 
/****************************************************************
The answer is to reverse the back half of the linked list to have the next attribute
 point to the previous node instead of the next node
 #Use two pointer fast and slow
 #find middle 
 #reverse the list fom slow ptr(MIDDLE) till end
 #Now traverse from first and last

 e.g
 1->2->3->4<-3<-2<-1(odd)
   1->2->3->3<-2<-1(even)
   #Mark next of (MIDDLE)prev as NULL and
  so while comparing always use last of list to traverse so that list automaticaly 
  stop at proper element check even case(at 3)
*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head)
        return true;
    LinkedListNode<int>* f=head,*s=head,*temp=NULL;
    while(f&&f->next){
        s=s->next;
        f=f->next->next;
    }
    //reverse the list from slow ptr
    LinkedListNode<int>* prev=s;
    s=s->next;
    //to stop backward iteration at middle(for odd /even)
    prev->next=NULL;
    while(s!=NULL){
        temp=s->next;
        s->next=prev;
        prev=s;
        s=temp;        
    }
    f=head,s=prev;
    while(s){
        if(f->data!=s->data)
            return false;
        f=f->next;
        s=s->next;
    }
    
    return true;
}