N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def lis(arr, i, n, prev):
    if i == n:
        return 0
    if memo[i][prev] != -1:
        return memo[i][prev]
    choice1 = lis(arr, i+1, n, prev)
    choice2 = 0
    if arr[i] >= arr[prev]:
        choice2 = 1 + lis(arr, i+1, n, i)
    memo[i][prev] = max(choice1, choice2)
    return memo[i][prev]

dp = [-1 for i in range(N)]

def lis_iterative(arr, n):
    dp[0] = 1
    for i in range(1, n):
        dp[i] = 1
        for j in range(i):
            if arr[i] >= arr[j] and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
    return max(dp)

n = 8
arr = [10, 22, 9, 33, 21, 50, 41, 60]
print("(Recursive) Length of LIS is", lis(arr, 0, n, 0))
print("(Iterative) Length of LIS is", lis_iterative(arr, n))
