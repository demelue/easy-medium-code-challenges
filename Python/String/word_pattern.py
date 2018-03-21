def word_pattern(pattern, s):
    s = s.split(" ")
    buff_dict = {}
    for i in range(len(pattern)):
        print(s[i],pattern[i])
        if pattern[i] not in buff_dict.keys():
            if s[i] not in buff_dict.values():
                buff_dict[pattern[i]] = s[i]
            else:
                print("different key same value")
                return False
        else:
            if buff_dict[pattern[i]] != s[i]:
                return False
    return True

if __name__ == '__main__':
    print(word_pattern("abba", "dog cat cat dog"))
