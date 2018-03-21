def find_median(num1, num2):
    num = num1 + num2
    num.sort()
    quo, rem = divmod(len(num), 2)

    if rem != 0:
        return num[quo]
    else:
        return (num[quo-1] + num[quo+1])/2.0


if __name__ == '__main__':
    print("Main")
    num1 = [4,7,6,5]
    num2 = [1,3,2,5]
    print(find_median(num1,num2))
