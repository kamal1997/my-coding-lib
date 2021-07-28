/*
Partition a set into two subsets such that the difference of subset sums is minimum

Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example: 

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11        
*/


#include <bits/stdc++.h>
using namespace std;

int minDifferencePartition(vector<int> arr) {

int n = arr.size();
int sum =0;

for(auto e: arr) {
    sum += e;
}


vector<vector<int>> dp(n+1, vector<int>(sum+1,0));

for(int i=0;i<=n;i++) {
    dp[i][0] =1;
}

for(int i=1;i<=sum;i++) {
    dp[0][i] =0;
}

for(int i=1;i<=n;i++) {
    for(int j=1;j<=sum;j++) {
        dp[i][j] = dp[i-1][j];
        if(arr[i-1]<=j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i-1]]);
        }
    }
}

int ans = INT_MAX;
for(int i=0;i<=sum/2;i++) {
    if(dp[n][i]==1) {
        ans = min(sum-2*i, ans);
    }
}

return ans;


}


int main() {
    int n,temp;
    vector<int> arr;

    cin>> n;
    for(int i=0;i<n;i++) {
        cin>>temp;
        arr.push_back(temp);
    }

    int result;
    result = minDifferencePartition(arr);
    cout<<result<<"\n";
}