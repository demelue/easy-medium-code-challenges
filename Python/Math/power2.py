def power2(n):
    if n == 0:
        return False
    else:
        return (n & (n - 1)) == 0

if __name__ == '__main__':

    n = 16
    print(power2(n))
