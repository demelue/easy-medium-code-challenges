def is_anagram_v1(word1, word2):
    char_count = [0]*26 #26 letters of alphabet
    if len(word1) != len(word2):
        return False

    for letter in word1:
        char_count[ord(letter) - ord('a')] += 1

    for letter in word2:
        if (char_count[ord(letter) - ord('a')] - 1) < 0:
            return False
        else:
            char_count[ord(letter) - ord('a')] -= 1
    return True

def is_anagram_v2(word1, word2):
    if len(word1) != len(word2):
        return False
    return sorted(word1) == sorted(word2)

#Time O(len(word)*N*M)
def group_anagram_v1(words):
    out_list = []
    i = 0
    while i < len(words):
        word = words.pop()
        j = 0
        tmp_list = []
        while j < len(words):
            if is_anagram_v1(word, words[j]):
                tmp_list.append(words.pop(j))
            j += 1
        tmp_list.append(word)
        out_list.append(tmp_list)
        i += 1

    return out_list

#Time O(N)
def group_anagram_v2(words):
    anagram_dict = {}
    for word in words:
        key = ''.join(sorted(word))
        if key not in anagram_dict:
            anagram_dict[key] = [word]
        else:
            anagram_dict[key].append(word)
    out_list = []

    for key in anagram_dict:
        out_list.append(anagram_dict[key])
    return out_list

#binary search tree

if __name__ == '__main__':
    words1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(group_anagram_v1(words1))
    words2 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(group_anagram_v2(words2))
