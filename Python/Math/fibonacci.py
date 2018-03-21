def fibonacci(num):
    if num == 1:
        return 1
    if num == 2:
        return 1

    return finbonacci(num-1) + finbonacci(num-2)


def fibonacci_v2_util(num, calc_values):
    if num == 1:
        return 1
    if num == 2:
        return 1
    if num in calc_values:
        return calc_values[num]
    else:
        out = fibonacci_v2_util(num-1, calc_values) + fibonacci_v2_util(num-2, calc_values)
        calc_values[num] = out
        return out

def fibonacci_v2(num):
    calc_values = dict()
    return fibonacci_v2_util(num, calc_values)



if __name__ == '__main__':

    # print(finbonacci(4))
    print(fibonacci_v2(7))
