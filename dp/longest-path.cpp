/*
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1. 
We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.
Example: 
 

Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}
Output: 4
The longest path is 6-7-8-9. 

*/

#include <bits/stdc++.h>
using namespace std;

const int n = 3;

int longestPath(int mat[][n], vector<vector<int>> dp, int m, int i, int j) {

    if(dp[i][j]!=0) {
        return dp[i][j];
    } 

    int temp = 0;

    if(i-1>=0 && mat[i-1][j]== mat[i][j]+1) {
        temp = max(temp, longestPath(mat, dp, m, i-1, j));
    }
    if(i+1<m && mat[i+1][j]== mat[i][j]+1) {
        temp = max(temp, longestPath(mat, dp, m, i+1, j));
    }
    if(j-1>=0 && mat[i][j-1] == mat[i][j]+1) {
        temp = max(temp, longestPath(mat, dp, m, i, j-1));
    }
    if(j+1<n && mat[i][j+1]== mat[i][j]+1) {
        temp = max(temp, longestPath(mat, dp, m, i, j+1));
    }

    

    dp[i][j] = temp +1;
    return dp[i][j];
    
}


int main() {

    int mat[][n] = {{1,2,9},{5,3,8},{4,6,7}};
    vector<vector<int>> dp(3, vector<int>(n+1, 0));
    int m =3;
    int result = INT_MIN;
    for(int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            result = max(longestPath(mat, dp, m, i, j), result);
        }
    }

    cout<<result<<"\n";

}