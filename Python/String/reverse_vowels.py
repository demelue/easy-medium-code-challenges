def reverse_vowels(s):
    vowel_list = ['a','e','i','o','u']
    slist = list(s)
    for i in range(len(slist)):
        if slist[i] in vowel_list:
            j = i + 1
            while j < len(slist):
                if slist[j] in vowel_list:
                    tmp = slist[i]
                    slist[i] = slist[j]
                    slist[j] = tmp
                    print(slist)
                    i = j
                    break
                j += 1
    return ''.join(slist)

if __name__ == '__main__':
    s = "house"
    print(reverse_vowels(s))
