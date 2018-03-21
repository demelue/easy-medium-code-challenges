def kth_frequent_string(words, k):

    buf = dict()
    for word in words:
        if word not in buf:
            buf[word] = 0
        buf[word] += 1

    output = []
    for data in buf:
        if buf[data] == k:
            output.append(data)

    return output


if __name__ == '__main__':
    words = ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"]
    # words = ["i", "love", "leetcode", "i", "love", "coding"]
    k = 4
    print(kth_frequent_string(words,k))
