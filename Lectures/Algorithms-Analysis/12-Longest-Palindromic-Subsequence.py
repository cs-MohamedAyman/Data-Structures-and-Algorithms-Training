N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def lps(s, i, j):
    if i > j:
        return 0
    if i == j:
        return 1
    if memo[i][j] != -1:
        return memo[i][j]
    if s[i] == s[j]:
        memo[i][j] = lps(s, i+1, j-1) + 2
        return memo[i][j]
    choice1 = lps(s, i, j-1)
    choice2 = lps(s, i+1, j)
    memo[i][j] = max(choice1, choice2)
    return memo[i][j]

dp = [[-1 for i in range(N)] for j in range(N)]

def lps_iterative(s, t, n):
    for i in range(n+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif s[i-1] == t[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][n]

n = 8
s = "ABBDCACB"
t = s[::-1]
print("(Recursive) Longest Palindrome Length is", lps(s, 0, n-1))
print("(Iterative) Longest Palindrome Length is", lps_iterative(s, t, n))
