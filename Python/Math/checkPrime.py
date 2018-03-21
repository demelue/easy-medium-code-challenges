def checkPrime(n):
    if n == 1:
        return True
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def countPrimes(n):
    """
    :type n: int
    :rtype: int
    """
    counter = 0;
    for i in range(1, n):
        if checkPrime(i) == True:
            counter+=1
    return counter

def isHappy(n):
    count = countPrimes(n)
    print(count)
    if (count - 1) % 2 == 0:
        return False
    return True


if __name__ == '__main__':
    n = 53
    # print(countPrimes(n))
    # print(checkPrime(17))
    print(isHappy(n))
