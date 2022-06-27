// we can solve it using simple Level order in reverse dirn
//
//we can also solve using dfs

//use next pointer to link right of a node to left of next node
Node* connect(Node* root) {
        Node* start=root;
        //go one level deep with outer loop
        while(start){
            Node* temp=start;            
            while(temp){
                if(temp->left!=NULL)
                    temp->left->next=temp->right;
                //if(next of right exist it have been already linked)
                if(temp->next!=NULL&&temp->right)
                    temp->right->next=temp->next->left;
                temp=temp->next;
                               
            }
            start=start->left;      
        }
        
        
        return root;

}