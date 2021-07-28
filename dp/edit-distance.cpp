/*

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

    Insert
    Remove
    Replace

All of the above operations are of equal cost. 

Examples: 

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a
*/

#include <bits/stdc++.h>
using namespace std;

int editDistance(string a, string b) {

int n,m,i,j;
m = a.length();
n = b.length();

if (m==0) {
    return n;
}

if(n==0) {
    return m;
}

vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

for(i=0;i<=m;i++){
    dp[i][0] = i;
}

for(i=0;i<=n;i++){
    dp[0][i] = i;
}


for(i=1;i<=m;i++) {
    for(j=1;j<=n;j++) {
        if(a[i-1]==b[j-1]) {
            dp[i][j] = dp[i-1][j-1];
        } else {
            dp[i][j] = 1+ min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
}

return dp[m][n];


}


int main() {
    string a, b;
    cin>>a>>b;
    int result;
    result = editDistance(a,b);
    cout<<result<<"\n";
}