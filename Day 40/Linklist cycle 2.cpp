#include <bits/stdc++.h> 
/****************************************************************
steps
1.use two pointer and find the colliding node
2.again start traversing fom head node and simultaneously from colliding Node
Both will meet at point where loop start

*****************************************************************/

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(head==NULL)
        return NULL;
    Node *f=head,*s=head;
    bool flag=false;
    while(f!=NULL&f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(s==f)
        {   
            flag=true;
            break;
        }
    }
    if(flag){
        f=head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        
        return s;
    }
    
    return NULL;
    
    
}