#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;

int memo[N];

int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int dp[N];

void fib_iterative() {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < N; i++)
		dp[i] = dp[i-1] + dp[i-2];
}

int main() {
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) fibonacci\n";
    cout << "fib 7: " << fib(7) << '\n';
    cout << "fib 6: " << fib(6) << '\n';
    cout << "fib 5: " << fib(5) << '\n';
    cout << "fib 4: " << fib(4) << '\n';
    cout << "fib 3: " << fib(3) << '\n';
    cout << "fib 2: " << fib(2) << '\n';
    cout << "(Iterative) fibonacci\n";
	fib_iterative();
    cout << "fib 7: " << dp[7] << '\n';
    cout << "fib 6: " << dp[6] << '\n';
    cout << "fib 5: " << dp[5] << '\n';
    cout << "fib 4: " << dp[4] << '\n';
    cout << "fib 3: " << dp[3] << '\n';
    cout << "fib 2: " << dp[2] << '\n';
}
