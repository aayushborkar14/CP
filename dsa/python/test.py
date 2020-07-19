for i in range(-5000, 5000):
    for j in range(-5000, 5000):
        if ((i**3)+(j**3)+((8-i-j)**3))==8:
            print(f"{i}, {j}, {8-i-j}")