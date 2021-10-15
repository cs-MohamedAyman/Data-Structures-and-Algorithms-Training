N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def lcs(X, Y, m, n):
    if m == -1 or n == -1:
        return 0
    if memo[m][n] != -1:
        return memo[m][n]
    if X[m] == Y[n]:
        memo[m][n] = 1 + lcs(X, Y, m-1, n-1)
        return memo[m][n]
    choice1 = lcs(X, Y, m, n-1)
    choice2 = lcs(X, Y, m-1, n)
    memo[m][n] = max(choice1, choice2)
    return memo[m][n]

def solution(X, Y, m, n):
    if m == -1 or n == -1:
        return ""
    if X[m] == Y[n]:
        return solution(X, Y, m-1, n-1) + X[m]
    if memo[m-1][n] > memo[m][n-1]:
        return solution(X, Y, m-1, n)
    else:
        return solution(X, Y, m, n-1)

dp = [[-1 for i in range(N)] for j in range(N)]

def lcs_iterative(X, Y, m, n):
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif X[i-1] == Y[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]

def solution_iterative(X, Y, m, n):
    res = dp[m][n]
    lcs_res = [''] * res
    i, j = m, n
    while i > 0 and j > 0:
        if X[i-1] == Y[j-1]:
            lcs_res[res-1] = X[i-1]
            i -= 1 ; j -= 1 ; res -= 1
        elif dp[i-1][j] > dp[i][j-1]: 
            i -= 1
        else:
            j -= 1
    return ''.join(lcs_res)

X = "AGGTAB"
Y = "GXTXAYB"
m = len(X)
n = len(Y)
print("(Recursive) Length of LCS is %d" % lcs(X, Y, m-1, n-1))
print("(Recursive) LCS of %s and %s is %s" % (X, Y, solution(X, Y, m-1, n-1)))
print("(Iterative) Length of LCS is %d" % lcs_iterative(X, Y, m, n))
print("(Iterative) LCS of %s and %s is %s" % (X, Y, solution_iterative(X, Y, m, n)))
