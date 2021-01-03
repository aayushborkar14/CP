num = ''

with open('temp_file.txt', mode='r') as my_file:
    num = my_file.read()

with open('temp_file.txt', mode='w') as my_file:
    my_file.write(num.replace('\n', '",\n"'))    
