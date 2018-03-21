#TOO SLOW
#bad run time complexity
def subsequence_string_util(s, occurence):
    i = 0
    while i < len(s):
        j = len(s)
        while j >= 0:
            if s[i:j] not in occurence:
                occurence.append(s[i:j])
            for k in range(1,len(s[i:j])):
                substr = list(s[i:j])
                del substr[k]
                subsequence_string_util(''.join(substr), occurence)
            j -= 1
        i += 1

def subsequence_string(s):
    occurence = []
    subsequence_string_util(s, occurence)
    print(occurence)

def is_palindrome(s):
    i = 0
    j = len(s)-1
    if j + 1 == 1:
        return True

    if s == "" or s == None:
        return False

    while s[i] == s[j]:
        if i > j:
            return True
        i += 1
        j -= 1
    return False

def longest_palindromic_subsequence_util(s, length, occurence):
    i = 0
    while i < len(s):
        j = len(s)
        while j >= 0:
            if s[i:j] not in occurence:
                if is_palindrome(s[i:j]):
                    length.append(len(s[i:j]))
                    print(s[i:j])
                    occurence[s[i:j]] = 1
            for k in range(1,len(s[i:j])):
                substr = list(s[i:j])
                del substr[k]
                longest_palindromic_subsequence_util(''.join(substr), length, occurence)
            j -= 1
        i += 1

def longest_palindromic_subsequence(s):
    length = []
    occurence = {}
    longest_palindromic_subsequence_util(s, length, occurence)
    print(occurence)
    return max(length)

if __name__ == '__main__':
    subsequence_string("aaa")
    # print(longest_palindromic_subsequence("baba"))
