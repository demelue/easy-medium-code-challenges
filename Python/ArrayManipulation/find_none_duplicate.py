#find the only none duplicate number in the number list
def find_none_duplicate_v1(nums):
    nums.sort()
    print(nums)
    i = 1
    while i < len(nums):
        print(str(nums[0]) + " ^ " + str(nums[i]) + " => " + str(nums[0] ^ nums[i]))
        nums[0] ^= nums[i]
        i += 1
    print("answer: ", nums[0])

def find_none_duplicate_v2(nums):
    print(nums)
    i = 1
    while i < len(nums):
        print(str(nums[0]) + " ^ " + str(nums[i]) + " => " + str(nums[0] ^ nums[i]))
        nums[0] ^= nums[i]
        i += 1
    print("answer: ", nums[0])

def find_none_duplicate_v3(nums):
    nums.sort()
    print(nums)
    i = 0
    while i < len(nums)-1:
        if nums[i] == nums[i + 1]:
            i += 2
        else:
            print(nums[i])
            break

if __name__ == '__main__':
    test1 = [6,4,1,-14,-9,7,-14,4,-9,6,1]
    find_none_duplicate_v1(test1)
    test2 = [-4,1,-14,1,7,-14,-4]
    find_none_duplicate_v2(test2)
    test3 = [-4,1,-14,1,7,-14,-4]
    find_none_duplicate_v3(test3)
