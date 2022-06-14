    #include <bits/stdc++.h> 
    #include <vector>
    //binary search concept
    // T.C->O(m+n) S.C->O(1)
    bool findTargetInMatrix(vector < vector < int >> & matrix, int m, int n, int target) {
        // Write your code here.
             if(target<matrix[0][0]&&target>matrix[m-1][n-1])
                return false;

            int i=0;
            int j=n-1;

            while(i<m&&j>=0){
                if(target==matrix[i][j]){
                    return true;
                }
                else if(target>matrix[i][j])
                    i++;
                else
                    j--;

            }                
           return false;
    }