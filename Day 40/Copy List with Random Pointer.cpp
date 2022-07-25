M1 using Map 
// T.C->O(n):S.C->O(N) 
LinkedList* clone()
    {
        // Initialize two references,
        // one with original list's head.
        Node *origCurr = head;
        Node *cloneCurr = NULL;
  
        // Hash map which contains node 
        // to node mapping of original 
        // and clone linked list.
        unordered_map<Node*, Node*> mymap;
  
        // Traverse the original list and
        // make a copy of that in the 
        // clone linked list.
        while (origCurr != NULL)
        {
            cloneCurr = new Node(origCurr->data);
            mymap[origCurr] = cloneCurr;
            origCurr = origCurr->next;
        }
  
        // Adjusting the original list 
        // reference again.
        origCurr = head;
  
        // Traversal of original list again
        // to adjust the next and random 
        // references of clone list using 
        // hash map.
        while (origCurr != NULL)
        {
            cloneCurr = mymap[origCurr];
            cloneCurr->next = mymap[origCurr->next];
            cloneCurr->random = mymap[origCurr->random];
            origCurr = origCurr->next;
        }
  
        // return the head reference of 
        // the clone list.
        return new LinkedList(mymap[head]);
    }




// M2  creating new Node in between the Nodes
// T.C->O(n):S.C->O(1) 

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL)
        return NULL;
    LinkedListNode<int> * temp=head;
    while(temp!=NULL){
        LinkedListNode<int> * n=new LinkedListNode<int>(temp->data);
        n->next=temp->next;
        temp->next=n;
        temp=n->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->next)
        temp->next->random=temp->random?temp->random->next:NULL;
        temp=temp->next?temp->next->next:temp->next;
    }
    LinkedListNode<int> *copy=head->next;
    LinkedListNode<int> *a=copy;
    temp=head;
    while(temp!=NULL&&a!=NULL){
        temp->next=  temp->next?  temp->next->next:  temp->next;
        a->next=a->next?a->next->next:a->next;
         temp=temp->next;
        a=a->next;
}
    
    return copy;
}
// Steps__>
// 1.Create the copy of node 1 and insert it between node 1 & node 2 and so on
// 2>original->next->random= original->random->next;  /*TRAVERSE 
// TWO NODES*/
// 3>Now restore the original and copy linked lists in this fashion in a single loop. 
// original->next = original->next->next;
//      copy->next = copy->next->next;