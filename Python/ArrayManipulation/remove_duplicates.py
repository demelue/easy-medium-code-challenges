def remove_duplicate_nums(nums):
    s = set()
    for num in nums:
        s.add(num)
    return s

def remove_duplicate_words(words):
    return set(words)

if __name__ == '__main__':
    nums = [10,20,34,20,56,78,34,78]
    print(remove_duplicate_nums(nums))

    words = "labamba"
    print(remove_duplicate_words(words))
