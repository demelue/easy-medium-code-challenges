def reverse_words_in_string_v1(s):
    s = s.split(' ')[::-1]
    out = []
    for i in range(len(s)):
        out.append(s[i] + ' ')
    return ''.join(out)

def reverse_words_in_string_v2(s):
    s = reversed(s.split(' '))
    out = []
    for val in s:
        out.append(val + ' ')
    return ''.join(out)

def reverse_word(s,i,j):
    while i < j:
        t = s[i]
        s[i] = s[j]
        s[j] = t
        i += 1
        j -= 1
    return s

def reverse_words_in_string_v3(s):
    slist = list(s)
    slist.append(' ')
    end_index = 0
    start_index = 0
    i = 0

    while i < len(s.split(' ')): #number of words
        while slist[end_index] != ' ':
            end_index += 1
        slist = reverse_word(slist, start_index, end_index - 1)
        end_index += 1
        start_index = end_index
        i += 1
    return ''.join(reverse_word(slist, 0, len(slist)-1)).strip(' ')

if __name__ == '__main__':
    s = "the sky is blue"
    print(reverse_words_in_string_v1(s))
    print(reverse_words_in_string_v2(s))
    print(reverse_words_in_string_v3(s))
