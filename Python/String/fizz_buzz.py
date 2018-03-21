def fizz_buzz(num):
    output = []
    for i in range(1, num+1):
        if (i % 3 == 0) and (i % 5 == 0):
            output.append("FizzBuzz")
        elif i % 5 == 0:
            output.append("Buzz")
        elif i % 3 == 0:
            output.append("Fizz")
        else:
            output.append(str(i))
    return output

def fizz_buzz_no_mod(num):
    fizz = 0
    buzz = 0
    output = []
    for i in range(1, num+1):
        fizz += 1
        buzz += 1

        if fizz == 3 and buzz == 5:
            fizz = 0
            buzz = 0
            output.append("FizzBuzz")
        elif fizz == 3:
            fizz = 0
            output.append("Fizz")
        elif buzz == 5:
            buzz = 0
            output.append("Buzz")
        else:
            output.append(str(i))
    return output


if __name__ == '__main__':
    num = 15
    print(fizz_buzz(num))
    print(fizz_buzz_no_mod(num))
