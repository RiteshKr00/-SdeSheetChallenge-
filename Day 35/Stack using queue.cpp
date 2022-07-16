#include<bits/stdc++.h>
class Stack {
	// Define the data members.

   public:
    
    queue<int>q1,q2;
    
    Stack() {
        // Implement the Constructor.
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(q1.size()==0)
            return -1;
        while(!q1.empty()&&q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        
        int x=q1.front();
        q1.pop();
        auto t=q1;
        q1=q2;
        q2=t;
        
        return x;
        
        
        
    }

    int top() {
        // Implement the top() function.
         if(q1.size()==0)
            return -1;
        while(!q1.empty()&&q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        
        int x=q1.front();
        q1.pop();
        q2.push(x);
        auto t=q1;
        q1=q2;
        q2=t;
        
        return x;
    }
};