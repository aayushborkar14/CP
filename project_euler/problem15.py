from math import factorial as fact

def C(n, r):
    return fact(n) / (fact(r) * fact(n-r))

print(C(20 + 20, 20))
