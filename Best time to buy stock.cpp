#include <bits/stdc++.h> 
//  here we have to find maximum +ve difference
// so we take two variable one to store min price and one to store maxm possible 
// =>profit=current price - least price

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int lsf = INT_MAX;
        int op = 0;
        int pist = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            pist = prices[i] - lsf;
            if(op < pist){
                op = pist;
            }
        }
        return op;

}