
def find_longest_substring(value):
    buff_dict = {}
    value = list(value)
    length = 0
    lenList = list()
    for i in range(0, len(value)):
        if value[i] in buff_dict:
            lenList.append(length)
            length = 0;
        else:
            buff_dict[value[i]] = i
            length += 1
    return max(lenList)

if __name__ == '__main__':
    value = "brutality"
    print("Longest distinct substring: " + str(find_longest_substring(value)))
