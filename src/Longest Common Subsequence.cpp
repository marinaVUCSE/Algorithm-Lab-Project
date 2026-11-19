#include<bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long int;

ll dp[1005][1005]; 
string ans = "";

int lcs_length(string &a, string &b, int i, int j) {

    if( i<0 || j<0 ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];

    if( a[i] == b[j] ) 
        return dp[i][j] = lcs_length( a, b, i-1, j-1 ) + 1;
    else {

        int op1 = lcs_length( a, b, i-1, j );
        int op2 = lcs_length( a, b, i, j-1 );

        return dp[i][j] = max( op1, op2 );
    }
}

void lcs(string &a, string &b, int i, int j) {
    if(i < 0 || j < 0) return;

    if(a[i] == b[j]) {
        lcs(a, b, i-1, j-1);
        ans += a[i];
    }
    else if(i > 0 && dp[i-1][j] > dp[i][j-1]) {
        lcs(a, b, i-1, j);
    }
    else
        lcs(a, b, i, j-1);
}

int main()
{
    string a, b; 
    cout << nl << "Enter two strings: ";
    cin >> a >> b;
    int n = a.size(), m = b.size();
    memset(dp, -1, sizeof(dp));

    int length = lcs_length( a, b, n-1, m-1 );
    lcs( a, b, n-1, m-1 );

    cout << "Longest Common Subsequence = " << ans
        << nl << "Length = " << length;

    return 0;
}