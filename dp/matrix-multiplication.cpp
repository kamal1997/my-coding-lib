

#include<bits/stdc++.h>
using namespace std;


int MatrixChainOrder(int arr[], int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    int i,j,k,l;

    for(i=1;i<n;i++) {
        dp[i][i] = 0;
    }

    for(i=2;i<n;i++) {
        for(j=1;j<n-i+1;j++) {
            l = j+i-1;
            dp[j][l] = INT_MAX;
            for(k=j;k<l;k++) {
                dp[j][l] = min(dp[j][l], dp[j][k]+dp[k+1][l]+arr[j-1]*arr[k]*arr[l]);
            }
            
        }
    }

    return dp[1][n-1];
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, size);
 
    return 0;
}