// T.C->O(N) S.C->O(N)
// use induction->hypothesis->baseCase method for intution


void insert(stack<int>&stack,int x)
{
    if(stack.empty()||stack.top()<x){
        stack.push(x);
        return;
    }
    int temp=stack.top();
    stack.pop();
    insert(stack,x);
    stack.push(temp);
    return;
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()||stack.size()==1)
        return;
    int x=stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack,x);
    return;
    
}