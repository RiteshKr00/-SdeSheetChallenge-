// T.C->O() Auxillary S.C->O(MlogN) 
// worst case t.c O(2^N) every digit result 2 digit but its not occur every time
// so T.C->O(N*L) S.C->O(L) 
// N= numer of iteration L=lenght of string at a level
// we store the string at each level aux space is O(N);
string say(string s){
    string t;    
    for(int i=0;i<s.length();i++){
        int cnt=1;
        while(i<s.length()-1&&s[i]==s[i+1]){
            i++;
            cnt++;
        }
        t.push_back(char('0'+cnt));
        t.push_back(s[i]);
        
    }
    return t;
    
}
string count(string s,int n){
    if(n==1)
        return s;
    string x=say(s);
    return count(x,n-1);
}
string writeAsYouSpeak(int n) 
{
	// Write your code here.
    return count("1",n);
}