def reverse_string_naive(inputStr):
    outStr = []
    j = len(inputStr) - 1
    for i in range(0, len(inputStr)):
        outStr.append(inputStr[j])
        j -= 1
    print (''.join(outStr))

def reverse_string_built_in(inputStr):
    print(''.join(reversed(inputStr)))

def reverse_string_elegant(inputStr):
    print(inputStr[::-1])

if __name__ == '__main__':
    reverse_string_naive("hello")
    reverse_string_built_in("yello")
    reverse_string_elegant("mother")
