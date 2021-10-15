#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

bool is_subsequence_sum(int* arr, int n, int curr_sum) {
    if (curr_sum == 0)
        return true;
    if (n == 0)
        return false;
    if (memo[n][curr_sum] != -1)
        return memo[n][curr_sum];
    if (arr[n-1] > curr_sum) {
        memo[n][curr_sum] = is_subsequence_sum(arr, n-1, curr_sum);
        return memo[n][curr_sum];
    }
    bool choice1 = is_subsequence_sum(arr, n-1, curr_sum);
    bool choice2 = is_subsequence_sum(arr, n-1, curr_sum - arr[n-1]);
    memo[n][curr_sum] = choice1 || choice2;
    return memo[n][curr_sum];
}

int dp[N][N];

bool is_subsequence_sum_iterative(int* arr, int n, int curr_sum) {
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= curr_sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= curr_sum; j++) {
            if (j < arr[i-1])
                dp[i][j] = dp[i-1][j];
            if (j >= arr[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][curr_sum];
}

int main() {
    int n = 7;
    int arr[] = {3, 34, 4, 12, 6, 5, 2};
    int total_sum = 15;
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) Is a Subsequence with the Given Sum " << is_subsequence_sum(arr, n, total_sum) << '\n';
    cout << "(Iterative) Is a Subsequence with the Given Sum " << is_subsequence_sum_iterative(arr, n, total_sum) << '\n';
}
