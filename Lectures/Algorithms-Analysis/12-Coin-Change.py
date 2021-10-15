N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def coin_change(arr, n, m):
    if m == 0:
        return 1
    if n == 0 or m < 0:
        return 0
    if memo[n][m] != -1:
        return memo[n][m]
    choice1 = coin_change(arr, n-1, m)
    choice2 = coin_change(arr, n, m-arr[n-1])
    memo[n][m] = choice1 + choice2
    return memo[n][m]

dp = [[-1 for i in range(N)] for j in range(N)]

def coin_change_iterative(arr, n, m):
    for i in range(n):
        dp[0][i] = 1
    for i in range(1, m+1):
        for j in range(n):
            x, y = 0, 0
            if i - arr[j] >= 0: 
                x = dp[i-arr[j]][j]
            if j >= 1:
                y = dp[i][j-1]
            dp[i][j] = x + y
    return dp[m][n-1]

n = 7
arr = [1, 5, 10, 20, 50, 100, 200]
total_sum = 20
print("(Recursive) # Coin Change", coin_change(arr, n, total_sum))
print("(Iterative) # Coin Change", coin_change_iterative(arr, n, total_sum))
