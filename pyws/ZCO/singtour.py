t = int(input())
for td in range(t):
    n = int(input())
    pitches = []
    for nd in range(n):
        liui = input()
        li = int(liui.split(" ")[0])
        ui = int(liui.split(" ")[1])
        pitches.append([li, ui])
    dp = [[-1 for i in range(n)] for j in range(n)]
    for i in range(n):
        dp[i][i] = 0
    for i in range(n):
        for j in range(i):
            if (dp[i][j] != -1):
                continue
            elif (pitches[i][0] < pitches[j][0] and pitches[i][1] > pitches[j][1]):
                dp[i][j] = 2
                dp[j][i] = 0
                for k in range(n):
                    if dp[j][k] == 2:
                        dp[i][k] = 2
            elif (pitches[i][0] > pitches[j][0] and pitches[i][1] < pitches[j][1]):
                dp[i][j] = 0
                dp[j][i] = 2
                for k in range(n):
                    if dp[i][k] == 2:
                        dp[j][k] = 2
            else:
                dp[i][j] = 1
                dp[j][i] = 1
    for i in range(n):
        print(sum(dp[i]), end=" ")
    print()
