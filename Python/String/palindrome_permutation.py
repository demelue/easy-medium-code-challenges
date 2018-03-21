def palindrome_permutation(s):
    freq = {}
    for v in s:
        if v not in freq:
            freq[v] = 1
        else:
            freq[v] += 1

    curr_sum = 0
    for i in freq.values():
        curr_sum += i % 2

    print(freq.values())
    print(freq.keys())
    print(curr_sum)

    if curr_sum > 1:
        return False
    else:
        return True

if __name__ == '__main__':
    palindrome_permutation("abdg")
