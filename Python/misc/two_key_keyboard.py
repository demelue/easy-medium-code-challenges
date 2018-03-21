def two_key_keyboard(n):

    res = 0
    for i in range(2,n):
        while n % i == 0:
            res += i
            n /= i
    return res

if __name__ == '__main__':
    # print("Min steps: ", two_key_keyboard(1))
    # print("Min steps: ", two_key_keyboard(2))
    # print("Min steps: ", two_key_keyboard(3))
    print("Min steps: ", two_key_keyboard(6))
