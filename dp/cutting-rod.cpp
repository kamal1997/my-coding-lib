

#include<bits/stdc++.h>
using namespace std;


/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 

*/

int maxRodCut(int arr[], int size, int n) {

    int dp[n+1] = {0};
    dp[0] = 0;
    dp[1] = arr[0];

    for(int i=2;i<=n;i++){
        dp[i] = arr[i-1];
        for(int j=1;j<i;j++) {
            dp[i] = max(dp[i], dp[j]+dp[i-j]);
        }
    }

    return dp[n];

}


int main()
{
    int arr[] = { 1, 5, 8, 9, 10,17, 17,20};
    int n=8;
    
    int size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "maximum yield"
         << maxRodCut(arr, size, n);
 
    return 0;
}