#include <bits/stdc++.h> 
/****************************************************************
// T.C->O(N)=k time for reversing and N/k times for recursing=o(k*N/k)
  S.C->O(N/k)stack space 

*****************************************************************/
int count(Node* head){
    int cnt=1;
    while(head->next!=NULL){
            head=head->next;
            cnt++;
        }
        return cnt;
}

Node *kreverse(Node *head,int n,int i,int b[]){
    if(head==NULL)
        return NULL;
    while(i<n&&b[i]==0)
        i++;
    if(i==n)
        return head;
    
    Node *t=head;
    int l=count(head);
//     cout<<l<<endl;
//     cout<<head->data;
    l=l>=b[i]?b[i]:l;
    Node* temp=head;
    Node* next1=NULL;
    Node* prev=NULL;
    int x=0;
    while(x<b[i]&&temp){
        next1=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next1;
        x++;
    }
    if(temp)
        head->next=kreverse(temp,n,i+1,b);
    
    return prev;
}


Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    if(head==NULL)
        return NULL;
    return kreverse(head,n,0,b);    
    
}