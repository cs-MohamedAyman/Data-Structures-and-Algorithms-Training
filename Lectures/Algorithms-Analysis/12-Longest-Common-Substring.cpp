#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int lcs(char* X, char* Y, int m, int n, int cnt) {
    if (m == -1 || n == -1)
        return cnt;
    if (memo[m][n] != -1)
        return memo[m][n];
	int choice1 = cnt, choice2 = 0, choice3 = 0;
    if (X[m] == Y[n])
        choice1 = lcs(X, Y, m-1, n-1, cnt+1);
    choice2 = lcs(X, Y, m, n-1, 0);
    choice3 = lcs(X, Y, m-1, n, 0);
	memo[m][n] = max(max(choice1, choice2), choice3);
    return memo[m][n];
}

int dp[N][N];

int lcs_iterative(char* X, char* Y, int m, int n) {
	int res = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
				res = max(res, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return res;
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "XGTAXYB";
    int m = strlen(X);
    int n = strlen(Y);
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) Length of LCS is " << lcs(X, Y, m-1, n-1, 0) << '\n';
    cout << "(Iterative) Length of LCS is " << lcs_iterative(X, Y, m, n) << '\n';
}
