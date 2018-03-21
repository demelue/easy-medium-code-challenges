def replace_words(s, wordDict):
    s = s.split(" ")
    out = ""
    for i,s_word in enumerate(s):
        for word in wordDict:
            if word in s_word:
                s[i] = word
        out += s[i] + " "

    print(out)



if __name__ == '__main__':
    words = ["cat", "bat", "rat"]
    sentence = "the cattle was rattled by the battery"

    replace_words(sentence, words)
