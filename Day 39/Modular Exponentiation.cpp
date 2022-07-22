// T.C->O(log n)
// here use 1LL to avoid skiping/oveflow of digit
// wrong :res=(res*x)%m;
// Right:res=(1LL*res*x)%m;

#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int res=1;
    x=x%m;
    while(n>0){
        if(n&1)
            res=(1LL*res*x)%m;
        n=n/2;
        x=(1LL*x*x)%m;
    }
    
    return res%m;
}

//recursive approach
  double pow(double x, int n)
    {
        if(n==0)
            return 1;
        
        double temp = pow(x,n/2);      //eases the process since we need not care about inc/dec
        
        if(n % 2 == 0)
            return temp * temp ;
        else
            return x * temp * temp ;
    }