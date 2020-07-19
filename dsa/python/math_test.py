import math

# for n in range(2014):
#     if (n + math.floor(n**0.5) + math.floor(n**(1/3))) == 2014:
#         print(n)

my_list = []

sum = 0

for i in range(1, 16):
    for j in range(1, 16):
        for k in range(1, 16):
            if (i + j + k) == 17:
                my_list.append(tuple((i, j, k)))

print(my_list)
list_len = len(my_list)
for x in my_list:
    sum += x[0]*x[1]*x[2]

print(sum)
