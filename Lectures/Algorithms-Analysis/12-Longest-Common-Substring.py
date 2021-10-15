N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def lcs(X, Y, m, n, cnt):
    if m == -1 or n == -1:
        return cnt
    if memo[m][n] != -1:
        return memo[m][n]
    choice1, choice2, choice3 = cnt, 0, 0
    if X[m] == Y[n]:
        choice1 = lcs(X, Y, m-1, n-1, cnt+1);
    choice2 = lcs(X, Y, m, n-1, 0)
    choice3 = lcs(X, Y, m-1, n, 0)
    memo[m][n] = max(choice1, choice2, choice3)
    return memo[m][n]

dp = [[-1 for i in range(N)] for j in range(N)]

def lcs_iterative(X, Y, m, n):
    res = 0
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif X[i-1] == Y[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
                res = max(res, dp[i][j])
            else:
                dp[i][j] = 0
    return res

X = "AGGTAB"
Y = "XGTAXYB"
m = len(X)
n = len(Y)
print("(Recursive) Length of LCS is", lcs(X, Y, m-1, n-1, 0))
print("(Iterative) Length of LCS is", lcs_iterative(X, Y, m, n))
