def bitwisePalindrome(num):
    #convert to binary string first
    numStr = str(bin(num))[2:]
    print (numStr)
    i = 0
    j = len(numStr)-1
    while (numStr[i] == numStr[j]):
        i += 1
        j -= 1

        if i > j:
            return True

    return False


if __name__ == '__main__':
    num = 9
    print(bitwisePalindrome(num))
    num = 13
    print(bitwisePalindrome(num))
