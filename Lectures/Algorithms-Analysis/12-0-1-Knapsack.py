N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def knapsack(total_wt, wt, val, n):
    if n == 0 or total_wt == 0:
        return 0
    if memo[total_wt][n] != -1:
        return memo[total_wt][n]
    if wt[n-1] > total_wt:
        memo[total_wt][n] = knapsack(total_wt, wt, val, n-1)
        return memo[total_wt][n]
    choice1 = knapsack(total_wt - wt[n-1], wt, val, n-1) + val[n-1]
    choice2 = knapsack(total_wt, wt, val, n-1)
    memo[total_wt][n] = max(choice1, choice2)
    return memo[total_wt][n]

def solution(total_wt, wt, val, n, v):
    if n == 0 or total_wt == 0:
        return
    v1, v2 = [], []
    if wt[n-1] > total_wt:
        return solution(total_wt, wt, val, n-1, v2)
    v1 += [n-1]
    choice1 = knapsack(total_wt - wt[n-1], wt, val, n-1) + val[n-1]
    choice2 = knapsack(total_wt, wt, val, n-1)
    if choice1 >= choice2:
        solution(total_wt - wt[n-1], wt, val, n-1, v1)
        for i in v1: v += [i]
    else:
        solution(total_wt, wt, val, n-1, v2)
        for i in v2: v += [i]

dp = [[-1 for i in range(N)] for j in range(N)]

def knapsack_iterative(total_wt, wt, val, n):
    for i in range(n+1):
        for w in range(total_wt+1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif wt[i-1] <= w:
                choice1 = dp[i-1][w-wt[i-1]] + val[i-1]
                choice2 = dp[i-1][w]
                dp[i][w] = max(choice1, choice2)
            else:
                dp[i][w] = dp[i-1][w]
    return dp[n][total_wt]

def solution_iterative(total_wt, wt, val, n):
    res = dp[n][total_wt]
    curr_w = total_wt
    i = n
    while i > 0 and res > 0:
        if res != dp[i-1][curr_w]:
            print("item %d with value %d" % (wt[i-1], val[i-1]))
            res -= val[i - 1]
            curr_w -= wt[i - 1]
        i -= 1

n = 7
val = [60, 100, 120, 180, 230, 110, 110]
wt = [10, 20, 30, 40, 50, 30, 20]
total_wt = 120
print("(Recursive) knapsack %d" % knapsack(total_wt, wt, val, n))
print("(Recursive) Selected items")
v = []
solution(total_wt, wt, val, n, v)
for i in v: print("item %d with value %d" % (wt[i], val[i]))
print("(Iterative) knapsack %d" % knapsack_iterative(total_wt, wt, val, n))
print("(Iterative) Selected items")
solution_iterative(total_wt, wt, val, n)
