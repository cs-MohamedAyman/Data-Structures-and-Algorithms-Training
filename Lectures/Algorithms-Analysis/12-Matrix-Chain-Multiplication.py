INT_MAX = 1 << 32
N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def matrix_chain(p, i, j):
    if i == j:
        return 0
    if memo[i][j] != -1:
        return memo[i][j]
    memo[i][j] = INT_MAX
    for k in range(i, j):
        choice = matrix_chain(p, i, k) + matrix_chain(p, k+1, j) + p[i-1] * p[k] * p[j]
        memo[i][j] = min(memo[i][j], choice)
    return memo[i][j]

dp = [[-1 for i in range(N)] for j in range(N)]

def matrix_chain_iterative(p, n):
    for i in range(1, n):
        dp[i][i] = 0
    for L in range(1, n):
        for i in range(1, n - L):
            j = i + L
            dp[i][j] = INT_MAX
            for k in range(i, j):
                choice = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]
                dp[i][j] = min(dp[i][j], choice)
    return dp[1][n-1]

n = 6
arr = [3, 2, 5, 2, 3, 5]
print("(Recursive) Minimum # Multiplications is", matrix_chain(arr, 1, n-1))
print("(Iterative) Minimum # Multiplications is", matrix_chain_iterative(arr, n))
