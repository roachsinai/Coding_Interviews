def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, y%x)

t1 = 10
t2 = 15

lcm = t1 * t2 / gcd(t1, t2)

print("least common multiple of {} and {} is\n {}".format(t1, t2, lcm))


# pythonic

def gcd(x, y):
    while y:
        x, y = y, x%y
    return x
