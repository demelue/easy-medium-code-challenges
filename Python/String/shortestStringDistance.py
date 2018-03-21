def shortestDistance(words, word1, word2):

    word1_indx = words.index(word1)
    word2_indx = words.index(word2)
    dist = abs(word1_indx - word2_indx)

    for i in range(0, len(words)):
        if words[i] == word1:
            if abs(i - word2_indx) < dist:
                word1_indx = i

        if words[i] == word2:
            if abs(i - word1_indx) < dist:
                word2_indx = i
        dist = abs(word1_indx - word2_indx)

    return dist

if __name__=='__main__':

    words = ['hi', 'lie', 'fly', 'my', 'why', 'die', 'lie']
    word1 = 'fli'
    word2 = 'die'

    print (shortestDistance(words, word1, word2))
