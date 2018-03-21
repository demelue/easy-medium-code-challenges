num2words1 = {1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five', \
            6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten', \
            11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen', \
            15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
num2words2 = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']

def wordMap(Number):
    if 1 <= Number < 19:
        return num2words1[Number]
    elif 20 <= Number <= 99:
        tens, below_ten = divmod(Number, 10)
        if (below_ten == 0 and tens > 1):
            return num2words2[tens - 2]
        else:
            return num2words2[tens - 2] + '-' + num2words1[below_ten]
    else:
        return "Number out of range"

def integer_to_english_words(num):

    if num == 0:
        return "zero"

    if num <= 99:
        return wordMap(num)

    counter = 0
    output = ""
    while (num > 99):
        if (len(str(num)) == 6):
            num -= 100000
            counter += 1
            if num < 100000:
                output += wordMap(counter) + " Hundred and "
                counter = 0
        elif (len(str(num)) == 5):
            num -= 10000
            counter += 1
            if num < 10000:
                counter = counter * 10;
        elif (len(str(num)) == 4):
            num -= 1000
            counter += 1
            if num < 1000:
                output += wordMap(counter) + " Thousand "
                counter = 0
        elif (len(str(num)) == 3):
            num -= 100
            counter += 1
            if num < 100:
                output += wordMap(counter) + " Hundred and " + wordMap(num)
        else:
            output = "Out of range"
    return output

if __name__ == '__main__':
    value = 999999
    print(integer_to_english_words(value))
