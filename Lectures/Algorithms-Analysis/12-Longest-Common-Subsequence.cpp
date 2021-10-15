#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int lcs(char* X, char* Y, int m, int n) {
    if (m == -1 || n == -1)
        return 0;
    if (memo[m][n] != -1)
        return memo[m][n];
    if (X[m] == Y[n]) {
        memo[m][n] = 1 + lcs(X, Y, m-1, n-1);
        return memo[m][n];
    }
    int choice1 = lcs(X, Y, m, n-1);
    int choice2 = lcs(X, Y, m-1, n);
    memo[m][n] = max(choice1, choice2);
    return memo[m][n];
}

string solution(char* X, char* Y, int m, int n) {
    if (m == -1 || n == -1)
        return "";
    if (X[m] == Y[n])
        return solution(X, Y, m-1, n-1) + X[m];
    if (memo[m-1][n] > memo[m][n-1])
        return solution(X, Y, m-1, n);
    else
        return solution(X, Y, m, n-1);
}

int dp[N][N];

int lcs_iterative(char* X, char* Y, int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

string solution_iterative(char* X, char* Y, int m, int n) {
    int res = dp[m][n];
	char lcs_res[res];
    int i = m, j = n;
    while (i > 0 && j > 0) { 
        if (X[i-1] == Y[j-1]) {
            lcs_res[res-1] = X[i-1];
            i --, j --, res --;
        }
        else if (dp[i-1][j] > dp[i][j-1]) 
			i --;
		else 
			j --;
   }
   return lcs_res;
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) Length of LCS is " << lcs(X, Y, m-1, n-1) << '\n';
    cout << "(Recursive) LCS of " << X << " and " << Y << " is " << solution(X, Y, m, n) << '\n';
    cout << "(Iterative) Length of LCS is " << lcs_iterative(X, Y, m, n) << '\n';
    cout << "(Iterative) LCS of " << X << " and " << Y << " is " << solution_iterative(X, Y, m, n) << '\n';
}
