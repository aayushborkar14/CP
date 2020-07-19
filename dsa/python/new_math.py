import math

number_of_int = 0
for n in range(1, 1025):
    control_bool = True
    for i in range(n):
        if math.ceil(n/2**i)%5 == 0:
            control_bool = False
            break
    if control_bool:
        number_of_int += 1

print(number_of_int)
