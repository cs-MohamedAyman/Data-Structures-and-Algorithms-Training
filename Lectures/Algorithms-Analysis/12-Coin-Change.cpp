  
#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int coin_change(int* arr, int n, int m) {
    if (m == 0)
        return 1;
    if (n == 0 || m < 0)
        return 0;
    if (memo[n][m] != -1)
        return memo[n][m];
    int choice1 = coin_change(arr, n-1, m);
    int choice2 = coin_change(arr, n, m-arr[n-1]);
    memo[n][m] = choice1 + choice2;
    return memo[n][m];
}

int dp[N][N];

int coin_change_iterative(int* arr, int n, int m) {
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= m; i++) { 
        for (int j = 0; j < n; j++) {
            int x = 0, y = 0;
            if (i-arr[j] >= 0) 
                x = dp[i-arr[j]][j];
            if (j >= 1) 
                y = dp[i][j-1];
            dp[i][j] = x + y;
        }
    }
    return dp[m][n-1];
}

int main() {
    int n = 7;
    int arr[] = {1, 5, 10, 20, 50, 100, 200};
    int total_sum = 20;
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) # Coin Change " << coin_change(arr, n, total_sum) << '\n';
    cout << "(Iterative) # Coin Change " << coin_change_iterative(arr, n, total_sum) << '\n';
}
