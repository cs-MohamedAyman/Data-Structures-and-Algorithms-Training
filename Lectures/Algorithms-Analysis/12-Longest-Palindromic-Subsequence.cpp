#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int lps(string s, int i, int j) {
    if (i > j)
        return 0;
    if (i == j)
        return 1;
	if (memo[i][j] != -1)
		return memo[i][j];
    if (s[i] == s[j]) {
        memo[i][j] = lps(s, i+1, j-1) + 2;
		return memo[i][j];
	}
	int choice1 = lps(s, i, j-1);
	int choice2 = lps(s, i+1, j);
    memo[i][j] = max(choice1, choice2);
	return memo[i][j];
}

int dp[N][N];

int lps_iterative(string s, string t, int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
            else if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main() {
    int n = 8;
    string s = "ABBDCACB";
	string t = s;
	reverse(t.begin(), t.end());
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) Longest Palindrome Length is " << lps(s, 0, n-1) << '\n';
    cout << "(Iterative) Longest Palindrome Length is " << lps_iterative(s, t, n) << '\n';
}
