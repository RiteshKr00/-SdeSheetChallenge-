// thought process

// ---- just convert each section till . to an integer  

// ---- and compare both if n1>n2 return 1 else if(n1<n2) return -1;

int compareVersions(string a, string b) 
{
    // Write your code here
    int i=0,j=0;
    int n=a.length(),m=b.length();
    while(i<n||j<m){
        long long n1=0,n2=0;
        while(i<n && a[i] != '.'){
            n1 = n1*10 + 1ll*(a[i]-'0');//convert int to ll
            i++;
        }
        while(j<m && b[j] != '.'){
            n2 = n2*10 + 1ll*(b[j]-'0');
            j++;
        }
        if(n1<n2){
            return -1;
        }
        else if(n1>n2)
            return 1;
        i++;j++;
        
    }
    return 0;
}