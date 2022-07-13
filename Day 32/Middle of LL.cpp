#include <bits/stdc++.h> 

Node *findMiddle(Node *head) {
    // Write your code here
    Node*sl=head,*ft=head;
    while(ft&&ft->next){
        sl=sl->next;
        ft=ft->next->next;        
    }
    return sl;
}