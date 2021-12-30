n = int(input())
arr = [int(x) for x in input().split()]

num_of_moves = 0
for i in range(1,n):
    if arr[i] < arr[i-1]:
        num_of_moves += arr[i-1] - arr[i]
        arr[i] = arr[i-1]        

print(num_of_moves)
