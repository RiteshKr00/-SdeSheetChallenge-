// T.C->O(N)  S.C->O(1) 
// To rotate a linked list by k, we can first make the linked list circular and then moving k-1 steps forward from head node, making (k-1)th node’s next to null and make kth node as head.
// BUt here clockwise so we will count the total node 
// then k will be int idx=count>k?count-k-1:count-(k%count)-1;

Node *rotate(Node *head, int k) {
     // Write your code here.
        if(head==NULL)
            return NULL;
         int len=1;
    Node *t1=head,*t2=head;
    while(t1->next!=NULL){
        len++;
        t1=t1->next;
    }
        t1->next=head;
        k=k%len;
        int l=len-k;
   while(--l){
       t2=t2->next;
   }
        head=t2->next;
        t2->next=NULL;
        
    return head;
}