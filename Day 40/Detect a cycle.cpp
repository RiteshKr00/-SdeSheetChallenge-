#include <bits/stdc++.h> 
/****************************************************************


*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    Node* f=head,*s=head;
    while(f!=NULL&&f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(f==s)
            return true;
    }
    
    return false;
    
}