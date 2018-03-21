#version 1
def word_break_util(s, wordDict, start):
    if start == len(s):
        return True
    end = start + 1
    while end <= len(s):
        print(s[start:end])
        if s[start:end] in wordDict and word_break_util(s, wordDict, end):
            return True
        end += 1
    return False

def word_break(s,wordDict):
    print(word_break_util(s, wordDict, 0))


def create_sub_strings_v1(s,start):
    if start == len(s):
        return
    print(s[start::])
    create_sub_strings_v1(s,start + 1)

def create_sub_strings_v2(s,start,end):
    if end == 0:
        return
    print(s[start:end])
    create_sub_strings_v2(s,start,end - 1)

if __name__ == '__main__':
    s = "leetcode"
    word_break(s, ["leet", "code"])
    # create_sub_strings_v2(s,0,len(s))
