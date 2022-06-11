#include <bits/stdc++.h> 
/****************************************************************
 calculate length of both linklist l1,l2 since length after intersection will be common 
 so we will subtract both length to get extra length of the linked list 
 Then skip that much lenght of largerlist 
 then compare on by one 
T.C->O(m+n) S.C->O(1)
*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
      Node *temp1=firstHead;
        Node *temp2=secondHead;
        
        int l1=0,l2=0;
        while(temp1!=NULL){
            l1++;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL){
            l2++;
            temp2=temp2->next;
        }
        temp1=firstHead;
        temp2=secondHead;
        if(l1>l2){
            int x=l1-l2;
            while(x--)
                temp1=temp1->next;
        }
        else{
            int x=l2-l1;
            while(x--)
                temp2=temp2->next;
        }
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1==temp2)
                return temp1->data;
            else
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }   
        
        return -1;
}