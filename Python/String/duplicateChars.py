def remove_duplicate(value):
    buff_dict = {}
    value = list(value)
    output = []
    for i in range(0, len(value)):
        if value[i] in buff_dict:
            print("Duplicate indices: " + str(i))
        else:
            output.append(value[i])
            buff_dict[value[i]] = i
    return ''.join(output)


if __name__ == '__main__':
    value = "singing"
    print("Remove Duplicates: " + remove_duplicate(value))
