#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int rod_cut(int* price, int rod_len, int n) {
    if (n == 0 || rod_len == 0)
        return 0;
	if (memo[n][rod_len] != -1)
		return memo[n][rod_len];
    if (n <= rod_len) {
		int choice1 = rod_cut(price, rod_len - n, n);
		int choice2 = rod_cut(price, rod_len, n-1);
        memo[n][rod_len] = max(price[n-1] + choice1, choice2);
    }
    else {
        memo[n][rod_len] = rod_cut(price, rod_len, n-1);
    }
    return memo[n][rod_len];
}

int dp[N][N];

int rod_cut_iterative(int* price, int rod_len, int n) {
    for (int i = 0; i <= rod_len; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0 || i == 0)
                dp[i][j] = 0;
            else if (j >= i)
                dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[rod_len][rod_len];
}

int main() {
    int n = 8;
    int price[] = {1, 5, 8, 9, 10, 14, 12, 20};
	int rod_len = 8;
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) Maximum of Rod Cutting is " << rod_cut(price, rod_len, n) << '\n';
    cout << "(Iterative) Maximum of Rod Cutting is " << rod_cut_iterative(price, rod_len, n) << '\n';
}
