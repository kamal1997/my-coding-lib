/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, 
either pick the complete item or don’t pick it (0-1 property).

*/
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)

int knapSack(int W, int wt[], int val[], int n) 
{ 

    vector< vector<int> > dp(n+1,vector<int>(W+1, 0));

    int i,j;

    for(i=1;i<=n;i++) {
        for(j=1;j<=W;j++) {
            dp[i][j] = dp[i-1][j];
            if(wt[i-1]<=j) {
                dp[i][j] = max(dp[i][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }
        }
    }

    return dp[n][W];



    
}

int main() {
    int W,n,i;
    cin>>W>>n;
    int wt[10001], val[10001];
    fo(i,n) {
        cin>>wt[i];
    }
    fo(i,n) {
        cin>>val[i];
    }

    int result;
    result = knapSack(W, wt, val, n);

    cout<<result<<"\n";

}