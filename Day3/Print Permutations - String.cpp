
void permute(vector<string> &ans,string a, int l, int r) 
{ 
    // Base case 
    if (l == r)
        ans.push_back(a);
    else
    { 
        for (int i = l; i <= r; i++) 
        { 
            swap(a[l], a[i]);       
            permute(ans,a, l+1, r);   
            swap(a[l], a[i]); 
        } 
    } 
} 
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    permute(ans,s,0,s.length()-1);
    return ans;
    // T.C->O(N* N!) there are n! permutations and it requires O(n) time to print a permutation.
    //   Auxilary S.C->O(N)

}