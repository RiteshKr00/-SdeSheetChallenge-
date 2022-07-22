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