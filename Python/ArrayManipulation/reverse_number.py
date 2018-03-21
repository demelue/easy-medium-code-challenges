def reverse_a_number_v1(num):
    sign = 1
    if num < 0:
        sign = -1
        num *= sign
    out = 0
    while num > 10:
        out *= 10
        out += num % 10
        num = int(num/10)

    out *= 10
    out += num % 10
    return (sign * out)

def reverse_a_number_v2(num):
    sign = 1
    if num < 0:
        sign = -1
        num *= sign
    out = 0

    while num != 0:
        out = (out * 10) + (num % 10)
        num = int(num/10)

    return (out * sign)

if __name__ == '__main__':
    print(reverse_a_number_v1(123))
    print(reverse_a_number_v2(-435))
