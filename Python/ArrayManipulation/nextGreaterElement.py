#swap two digits no temp variable
#NOTE must be integers
def swap(i, j):
    print([i, j])
    i = i + j
    j = i - j
    i = i - j
    print([i, j])

def nextGreaterElement(n):

    nStr = list(str(n))
    print(nStr)

    i = len(nStr) - 2
    print("initial i value: " + str(i))
    while (i >= 0 and nStr[i + 1] <= nStr[i]):
        i = i - 1

    if (i < 0):
        return -1

    j = len(nStr) - 1
    while (j >= 0 and nStr[j] <= nStr[i]):
        j = j - 1

    print ([i, j])

    tmp = nStr[i]
    nStr[i] = nStr[j]
    nStr[j] = tmp

    out = nStr[: i + 1] + list(reversed(nStr[i + 1:])) #check if slicing is inclusive

    print(int(''.join(out)))

if __name__ == '__main__':

    value = 1276
    nextGreaterElement(value)
