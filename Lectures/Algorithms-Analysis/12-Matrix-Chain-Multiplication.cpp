#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int matrix_chain(int* p, int i, int j) { 
    if (i == j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    memo[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int choice = matrix_chain(p, i, k) + matrix_chain(p, k+1, j) + p[i-1] * p[k] * p[j];
        memo[i][j] = min(memo[i][j], choice);
    }
    return memo[i][j];
}

int dp[N][N];

int matrix_chain_iterative(int* p, int n) {
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int L = 1; L < n; L++) {
        for (int i = 1; i < n - L; i++) {
            int j = i + L;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int choice = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], choice);
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int n = 6;
    int arr[] = {3, 2, 5, 2, 3, 5};
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) Minimum # Multiplications is " << matrix_chain(arr, 1, n-1) << '\n';
    cout << "(Iterative) Minimum # Multiplications is " << matrix_chain_iterative(arr, n) << '\n';
}
