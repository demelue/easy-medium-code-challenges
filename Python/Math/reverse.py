def reverse(num):

    output = list(str(num))
    if output[0] == '-':
        output = output[1:]
        output = output[::-1]
        output.insert(0,'-')
    else:
        output = output[::-1]

    if output > pow(2,32)-1:
        print('Overlow')
        return 0
        
    return int(''.join(output))


if __name__ == '__main__':
    num = 124
    print(reverse(num))
    num = -124
    print(reverse(num))
