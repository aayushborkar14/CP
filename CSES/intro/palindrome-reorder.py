in_str = str(input())
my_dict = {}
for c in in_str:
    if c in my_dict:
        my_dict[c] += 1
    else:
        my_dict[c] = 1

str_front = ''
odd = False
no_sol = False
middle = ''
for c in my_dict.keys():
    if my_dict[c] % 2 == 0:
        str_front += c * int(my_dict[c]/2)
    else:
        if odd == False:
            middle = c
            odd = True
        else:
            print('NO SOLUTION')
            no_sol = True
            break

if no_sol == False:
    if odd:
        full_str = str_front + \
            (middle*int(my_dict[middle])) + (str_front[::-1])
        print(full_str)
    else:
        full_str = str_front + (str_front[::-1])
        print(full_str)
