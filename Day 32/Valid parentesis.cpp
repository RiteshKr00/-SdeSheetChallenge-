bool isValidParenthesis(string e)
{
    // Write your code here.
    stack<char>s;
    for(int i=0;i<e.length();i++){
        if(e[i]=='['||e[i]=='('||e[i]=='{'){
            s.push(e[i]);
        }
        else {
            if(s.empty())
                return false;
            else if((e[i]==']'&&s.top()=='[')||(e[i]=='}'&&s.top()=='{')||(e[i]==')'&&s.top()=='('))
            s.pop();
        else
            return false;
        }        
    }
    if(!s.empty())
        return false;
    return true;
}