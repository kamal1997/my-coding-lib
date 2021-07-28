/*
Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
Note: The opponent is as clever as the user.

Input
{ 8, 15, 3, 7 }
output
22
{ 2, 2, 2, 2 }
output
4
{ 20, 30, 2, 2, 2, 10 }
42

*/

#include <bits/stdc++.h>
using namespace std;


int optimalStrategy(int arr[], int n, int i, int j, vector<vector<int>> &dp) {
    if(i>j) {
        return 0;
    }

    if(i<0 || i>=n || j<0 || j>=n ) {
        return 0;
    }

    if(dp[i][j]!=0) {
        return dp[i][j];
    }
 

    dp[i][j] = max(arr[i] + min(optimalStrategy(arr, n, i+2, j, dp), optimalStrategy(arr, n, i+1, j-1, dp)), arr[j] + min(optimalStrategy(arr, n, i, j-2, dp), optimalStrategy(arr, n, i+1, j-1, dp)));


    return dp[i][j];




    
}


int main() {

    int arr[] = { 20, 30, 2, 2, 2, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> dp(n, vector<int>(n,0));

    int result = optimalStrategy(arr,n, 0, n-1, dp);
   

    cout<<result<<"\n";

}