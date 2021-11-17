#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int knapsack(int total_wt, int* wt, int* val, int n) {
    if (n == 0 || total_wt == 0)
        return 0;
    if (memo[total_wt][n] != -1)
        return memo[total_wt][n];
    if (wt[n-1] > total_wt) {
        memo[total_wt][n] = knapsack(total_wt, wt, val, n-1);
        return memo[total_wt][n];
    }
    int choice1 = knapsack(total_wt - wt[n-1], wt, val, n-1) + val[n-1];
    int choice2 = knapsack(total_wt, wt, val, n-1); 
    memo[total_wt][n] = max(choice1, choice2);
    return memo[total_wt][n];
}

void solution(int total_wt, int* wt, int* val, int n, vector<int> &v) {
    if (n == 0 || total_wt == 0)
        return;
    vector<int> v1, v2;
    if (wt[n-1] > total_wt)
        return solution(total_wt, wt, val, n-1, v2);
    v1.push_back(n-1);
    int choice1 = knapsack(total_wt - wt[n-1], wt, val, n-1) + val[n-1];
    int choice2 = knapsack(total_wt, wt, val, n-1);
    if (choice1 >= choice2) {
        solution(total_wt - wt[n-1], wt, val, n-1, v1);
        for (int i : v1) v.push_back(i);
    }
    else {
        solution(total_wt, wt, val, n-1, v2);
        for (int i : v2) v.push_back(i);
    }
}

int dp[N][N];

int knapsack_iterative(int total_wt, int* wt, int* val, int n) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= total_wt; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w) {
                int choice1 = dp[i-1][w-wt[i-1]] + val[i-1];
                int choice2 = dp[i-1][w];
                dp[i][w] = max(choice1, choice2);
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][total_wt];
}

void solution_iterative(int total_wt, int* wt, int* val, int n) {
    int res = dp[n][total_wt];
    int curr_w = total_wt;
	int i = n;
    while (i > 0 && res > 0) {
        if (res != dp[i-1][curr_w]) {
			cout << "item " << wt[i-1] << " with value " << val[i-1] << '\n';
			res -= val[i - 1];
			curr_w -= wt[i - 1];
		}
		i --;
    }
}

int main() {
    int n = 7;
    int val[] = {60, 100, 120, 180, 230, 110, 110}; 
    int wt[] = {10, 20, 30, 40, 50, 30, 20}; 
    int total_wt = 120;
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) knapsack " << knapsack(total_wt, wt, val, n) << '\n';
    cout << "(Recursive) Selected items\n";
    vector<int> v;
    solution(total_wt, wt, val, n, v);
    for (int i : v) cout << "item " << wt[i] << " with value " << val[i] << '\n';
    cout << "(Iterative) knapsack " << knapsack_iterative(total_wt, wt, val, n) << '\n';
    cout << "(Iterative) Selected items\n";
	solution_iterative(total_wt, wt, val, n);
}
