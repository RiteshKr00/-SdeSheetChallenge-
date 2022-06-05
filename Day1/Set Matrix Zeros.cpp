// Q.Set Matrix Zeros
//Notes
// Rather than using additional variables to keep track of rows and columns to be reset,
//  we use the matrix itself as the indicators.
//  i.e Use first Row and column as a set and to mark rows and col Zeros
//  and for first row and col use two extra variable to track whether it is zero or not
// My Solution
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    set<int>row,col;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for(auto it:row){
            for(int j=0;j<matrix[0].size();j++){
                matrix[it][j]=0;
            }
    }
    for(auto it:col){
            for(int j=0;j<matrix.size();j++){
                matrix[j][it]=0;
            }
    }   
}
//optimisedCode
//  void setZeroes(vector<vector<int>>& matrix) {
//         bool isrow=false;
//         bool iscol=false;
//         for(int i=0,j=0;i<matrix.size();i++){
//             if(matrix[i][j]==0){
//                 iscol=true;
//                 break;
//             }
//          }
//         for(int i=0,j=0;j<matrix[0].size();j++){
//             if(matrix[i][j]==0){
//                 isrow=true;
//                 break;
//             }
//          }
        
//         for(int i=1;i<matrix.size();i++){
//             for(int j=1;j<matrix[0].size();j++){
//                 if(matrix[i][j]==0){
//                     matrix[0][j]=0;
//                      matrix[i][0]=0;
//                 }
//             }
//         }
//          for(int i=1;i<matrix.size();i++){
//             for(int j=1;j<matrix[0].size();j++){
//                 if(matrix[i][0]==0||matrix[0][j]==0){
//                     matrix[i][j]=0;;
//                 }
//             }
//         }
//         if(iscol){
//             for(int i=0,j=0;i<matrix.size();i++){
//                 matrix[i][0]=0;
//             }
//         }
//          if(isrow){
//             for(int i=0,j=0;j<matrix[0].size();j++){
//                 matrix[0][j]=0;
//             }
//         }
        
        
//          for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                cout<<matrix[i][j]<<" ";
//             }
//              cout<<endl;
//         }
        
//     }

