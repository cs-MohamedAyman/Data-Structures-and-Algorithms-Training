N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def is_subsequence_sum(arr, n, curr_sum):
    if curr_sum == 0:
        return 1
    if n == 0:
        return 0
    if memo[n][curr_sum] != -1:
        return memo[n][curr_sum]
    if arr[n-1] > curr_sum:
        memo[n][curr_sum] = is_subsequence_sum(arr, n-1, curr_sum)
        return memo[n][curr_sum]
    choice1 = is_subsequence_sum(arr, n-1, curr_sum)
    choice2 = is_subsequence_sum(arr, n-1, curr_sum - arr[n-1])
    memo[n][curr_sum] = choice1 | choice2
    return memo[n][curr_sum]

dp = [[-1 for i in range(N)] for j in range(N)]

def is_subsequence_sum_iterative(arr, n, curr_sum):
    for i in range(n+1):
        dp[i][0] = 1
    for i in range(1, curr_sum+1):
        dp[0][i] = 0
    for i in range(1, n+1):
        for j in range(1, curr_sum+1):
            if j < arr[i-1]:
                dp[i][j] = dp[i-1][j]
            if j >= arr[i-1]:
                dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]]
    return dp[n][curr_sum]

n = 7
arr = [3, 34, 4, 12, 6, 5, 2]
total_sum = 15
print("(Recursive) Is a Subsequence with the Given Sum", is_subsequence_sum(arr, n, total_sum))
print("(Iterative) Is a Subsequence with the Given Sum", is_subsequence_sum_iterative(arr, n, total_sum))
