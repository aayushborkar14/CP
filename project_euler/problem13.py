sum = 0

with open('problem13.txt', mode='r') as my_file:
    for i in range(100):
        sum += int(my_file.readline())

print(sum)
