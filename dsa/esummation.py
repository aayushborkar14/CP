from mpmath import nsum, exp, inf

print(nsum(lambda n: (n**2)*exp(-n), [1, inf]))