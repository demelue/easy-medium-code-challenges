

def divide(dividend, divisor):
    positive = (dividend < 0) is (divisor < 0)
    dividend, divisor = abs(dividend), abs(divisor)
    res = 0
    # while dividend >= divisor:
    #     temp, i = divisor, 1
    while dividend >= divisor:
        dividend -= divisor
        res += 1
            # i <<= 1
            # temp <<= 1
    if not positive:
        res = -res
    return min(max(-2147483648, res), 2147483647)
    return res

if __name__ == '__main__':

    print(divide(65,2))
