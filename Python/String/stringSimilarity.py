def string_similarity(word):
    word_list = list(word)
    total_similarity_count = 0
    for i in range(1,len(word)):
        word_list.pop(0)
        word_index = 0
        similiarity_count = 0
        while word_index < len(word_list):
            if word[word_index] == word_list[word_index]:
                similiarity_count += 1
            else:
                break
            word_index += 1
        total_similarity_count += similiarity_count
    # print(total_similarity_count + len(word))
    return total_similarity_count + len(word)

if __name__ == '__main__':
    print(string_similarity("ababaa"))
    print(string_similarity("aa"))
