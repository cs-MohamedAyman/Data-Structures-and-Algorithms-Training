#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int lis(int* arr, int i, int n, int prev) {
    if (i == n)
        return 0;
	if (memo[i][prev] != -1)
		return memo[i][prev];
    int choice1 = lis(arr, i+1, n, prev);
    int choice2 = 0;
    if (arr[i] >= arr[prev])
        choice2 = 1 + lis(arr, i+1, n, i);
    memo[i][prev] = max(choice1, choice2);
	return memo[i][prev];
}

int dp[N];

int lis_iterative(int* arr, int n) {
    dp[0] = 1;  
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
    return *max_element(dp, dp+n);
}

int main() {
    int n = 8;
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) Length of LIS is " << lis(arr, 0, n, 0) << '\n';
    cout << "(Iterative) Length of LIS is " << lis_iterative(arr, n) << '\n';
}
