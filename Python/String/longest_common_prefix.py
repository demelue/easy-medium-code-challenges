def longest_common_prefix_v1(strs):
    output = []
    smallest_size = len(strs[0])
    i = 0
    flag = False
    while i < smallest_size:
        j = 1
        current_letter = strs[0][i]
        while j < len(strs):
            #update size
            if len(strs[j]) < smallest_size:
                smallest_size = len(strs[j])

            if strs[j][i] == current_letter:
                flag = True
            else:
                flag = False
                break
            j += 1
        if flag:
            output.append(current_letter)
        i += 1
    return output

if __name__=='__main__':
    words = ['sum', 'slump', 'slug', 'slugger', 'slumber']
    print(longest_common_prefix_v1(words))
