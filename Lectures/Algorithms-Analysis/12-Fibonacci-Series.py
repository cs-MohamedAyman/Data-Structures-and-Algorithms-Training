N = int(2e5+3)

memo = [-1 for i in range(N)]

def fib(n):
    if n == 0 or n == 1:
        return n
    if memo[n] != -1:
        return memo[n]
    memo[n] = fib(n-1) + fib(n-2)
    return memo[n]

dp = [-1 for i in range(N)]

def fib_iterative():
    dp[0], dp[1] = 0, 1
    for i in range(2, N):
        dp[i] = dp[i-1] + dp[i-2]

print("(Recursive) fibonacci")
print("fib 7:", fib(7))
print("fib 6:", fib(6))
print("fib 5:", fib(5))
print("fib 4:", fib(4))
print("fib 3:", fib(3))
print("fib 2:", fib(2))
print("(Iterative) fibonacci")
fib_iterative()
print("fib 7:", dp[7])
print("fib 6:", dp[6])
print("fib 5:", dp[5])
print("fib 4:", dp[4])
print("fib 3:", dp[3])
print("fib 2:", dp[2])
