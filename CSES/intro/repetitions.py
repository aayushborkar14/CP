in_str = str(input())
prev = ''
max_length = 0
current_length = 1

for c in in_str:
    if c == prev:
        current_length += 1
    else:
        prev = c
        if (current_length >= max_length):
            max_length = current_length
        current_length = 1

if (current_length >= max_length):
    max_length = current_length
print(max_length)
