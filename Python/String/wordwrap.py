# The quick brown fox jumps over the lazy dog

# wordwrap('The quick brown fox jumps over the lazy dog', 20)

# The quick brown | 18
# fox jumps over  | 18
# the lazy dog    | 18

# 'The quick brown fox\njumps over the lazy\ndog'
#Time O(N) space O(N)
def wordwrap(s, col):
    col_rem = col
    wordList = s.split(' ')
    output = []

    for word in wordList:
        col_rem -= len(word)
        if col_rem < 0: #case were the word doesn't fit
            output.append('\n' + word + ' ')
            col_rem = col - (len(word) + 1)
        elif col_rem == 0: #case were the number of words fit the column including spaces exactly
            output.append(word + '\n')
            col_rem = col
        else: #case were there is enough space to fit the word and space cause greater than
            output.append(word + ' ')
            col_rem -= 1 #remove 1 for the space as well


    return ''.join(output)

#NOTE BAD WAY OF ADDRESSING PROBLEM
def wordwrapv2(s,col):
    col_count = col
    space_indx = 0
    output_str = list(s)
    for i,character in enumerate(s):
        if character == ' ':
            space_indx = i
            # print(wordendindx)
        if col_count == 0:
            output_str.insert(space_indx,'\n')
            if output_str[space_indx + 1] == ' ':
                del output_str[space_indx + 1]

            letters_after_space = i - space_indx
            if character != ' ':
                col_count = col - letters_after_space
                j = i
                # print(i)
                while j < len(output_str):
                    if output_str[j] == ' ':
                        space_indx = j
                        break
                    j += 1
                if j == len(output_str):
                    break
            else:
                col_count = col

            # print(letters_after_space,space_indx)
        col_count -= 1
    return ''.join(output_str)

if __name__ == '__main__':
    print(wordwrap('The quick brown foxx jumps over the lazy dog',10))
    # print(wordwrapv2('The quick brown fox jumps over the lazy dog',10))
