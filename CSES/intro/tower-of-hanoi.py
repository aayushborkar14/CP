n = int(input())

dp = {}

for i in range(n+1):
    dp[i] = -1

dp[1] = [[1, 3]]
if n != 1:
    dp[2] = [[1, 2], [1, 3], [2, 3]]

# swaps all occurences of num1 with num2 and vice versa in a list
def swap(my_list, num1, num2):
    dup_list = my_list.copy()
    for i in range(len(dup_list)):
        if dup_list[i] == num1:
            dup_list[i] = num2
        elif dup_list[i] == num2:
            dup_list[i] = num1
    return dup_list

for i in range(3, n+1):
    dp[i] = []
    for elem in dp[i-1]:
        dp[i].append(swap(elem, 2, 3))
    dp[i].append([1, 3])
    for elem in dp[i-1]:
        dp[i].append(swap(elem, 1, 2))

print(len(dp[n]))
for elem in dp[n]:
    print(elem[0], elem[1])
