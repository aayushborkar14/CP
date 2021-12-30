n = int(input())
dp = {}
dp[1] = ['0', '1']
dp[2] = ['00', '01', '11', '10']

for i in range(3, n+1):
    dp[i] = -1

def Reverse(lst):
    return [ele for ele in reversed(lst)]

def rec(n):
    if n == 1:
        return dp[1]
    elif n == 2:
        return dp[2]
    else:
        if dp[n] == -1:
            dp[n] = []
            for te_str in rec(n-1):
                dp[n].append('0' + te_str)
            for te_str in Reverse(rec(n-1)):
                dp[n].append('1' + te_str)
            return dp[n]
        else:
            return dp[n]

for num in rec(n):
    print(num)
