#find all permutations of the word list
#in the input string
#given a list of words ["a","b","c"] find all combinations of them in an input
#string s = "abcabdfcbaebcacb" as a substring output = [0,1,2,7,11,13]

def sliding_window(word_str, word_list):

    if word_str == None or word_str == " ":
        return []

    if len(word_str) < len(word_list):
        return []

    s = 0
    e = 0
    count = 0
    used = {}
    output = []
    while e < len(word_str):
        if word_str[e] in word_list:
            if word_str[e] not in used:
                used[word_str[e]] = 0

            if used[word_str[e]] == 1:
                s += 1
                e = s
            else:
                used[word_str[e]] = 1
                count += 1
                print("Found => ", word_str[e])
        else:
            print("Reset")
            used = {}
            s = e + 1
            count = 0

        if count == len(word_list):
            used[word_str[s]] = 0
            print("Used =>", used.values(), used.keys())
            output.append(s)
            s += 1
            e = s
            count = 0
            used = {}
        e += 1
    print(output)


class anagramSearch(object):
    def findAnagrams(self, s, p):
        if len(s) < len(p):
            return []
        result = []
        wordFrequencies = [0 for i in range(26)]
        curFrequencies = [0 for i in range(26)]
        for i, char in enumerate(p):
            char = self.getNumFromChar(char)
            wordFrequencies[char] += 1
            sChar = self.getNumFromChar(s[i])
            curFrequencies[sChar] += 1
        ptr1 = 0
        ptr2 = len(p)

        print(wordFrequencies,curFrequencies)
        
        while ptr2 < len(s):
            if self.compare(wordFrequencies, curFrequencies):
                result.append(ptr1)
            startChar = self.getNumFromChar(s[ptr1])
            endChar = self.getNumFromChar(s[ptr2])
            curFrequencies[startChar] -= 1
            curFrequencies[endChar] += 1
            ptr1 += 1
            ptr2 += 1
        if self.compare(wordFrequencies, curFrequencies):
            result.append(ptr1)
        return result

    def compare(self, freq1, freq2):
        for i in range(len(freq1)):
            if freq1[i] != freq2[i]:
                return False
        return True

    def getNumFromChar(self, char):
        return ord(char)-ord('a')

if __name__ == '__main__':
    word_str = "abcabdfcbaebcacb"
    word_list = ["a","b","c"]
    # sliding_window(word_str, word_list)

    test_func = anagramSearch()
    print(test_func.findAnagrams(word_str, word_list))
