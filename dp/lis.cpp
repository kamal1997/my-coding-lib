/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 

*/

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)

int lis(int arr[], int n) 
{ 

    vector<int> dp(n,0);

    int i,j;

    dp[n-1] = 1;

    for(i=n-2;i>=0;i--) {
        dp[i] =1;
        for(j=i+1;j<n;j++) {
            if(arr[i] < arr[j]) {
                dp[i] = max(dp[i], 1+dp[j]);
            }
            
        }
    }

    return dp[0];
    



    
}

int main() {
    int n,i;
    cin>>n;
    int arr[10001];
    fo(i,n) {
        cin>>arr[i];
    }

    int result;
    result = lis(arr, n);

    cout<<result<<"\n";

}