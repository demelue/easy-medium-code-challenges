
def power3(n):

    if (n == 0):
        return False

    while (n % 3 == 0):
        n /= 3
    return n == 1

def power3_for_32_bit(n):
    if (n == 0):
        return False
    else:
        #largest 32 bit power of 3 number
        return (n > 0) and (1162261467 % n == 0)

if __name__ == '__main__':

    n = 27
    print("First method")
    print(power3(n))

    print("Second method")
    print(power3_for_32_bit(n))
