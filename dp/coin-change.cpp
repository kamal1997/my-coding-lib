

#include<bits/stdc++.h>
using namespace std;


/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

*/

int count(int arr[], int size, int n) {
    int dp[n+1][size+1] = {0};


    for(int i=0;i<=size;i++) {
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++) {
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=size;j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i-1]<=size) {
                dp[i][j] += dp[i][j-arr[i-1]];
            }
        }
     }

     return dp[n][size];



}


int main()
{
    int arr[] = { 1, 2, 3};
    int n=4;
    
    int size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "maximum number of ways"
         << count(arr, size, n);
 
    return 0;
}