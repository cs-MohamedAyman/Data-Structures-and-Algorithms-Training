N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def rod_cut(price, rod_len, n):
    if n == 0 or rod_len == 0:
        return 0
    if memo[n][rod_len] != -1:
        return memo[n][rod_len]
    if n <= rod_len:
        choice1 = rod_cut(price, rod_len - n, n)
        choice2 = rod_cut(price, rod_len, n-1)
        memo[n][rod_len] = max(price[n-1] + choice1, choice2)
    else:
        memo[n][rod_len] = rod_cut(price, rod_len, n-1)
    return memo[n][rod_len]

dp = [[-1 for i in range(N)] for j in range(N)]

def rod_cut_iterative(price, rod_len, n):
    for i in range(rod_len+1):
        for j in range(n+1):
            if j == 0 or i == 0:
                dp[i][j] = 0
            elif j >= i:
                dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-i])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[rod_len][rod_len]

n = 8
price = [1, 5, 8, 9, 10, 14, 12, 20]
rod_len = 8
print("(Recursive) Maximum of Rod Cutting is", rod_cut(price, rod_len, n))
print("(Iterative) Maximum of Rod Cutting is", rod_cut_iterative(price, rod_len, n))
