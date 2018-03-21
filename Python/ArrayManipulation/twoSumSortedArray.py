#Sorts array first

def twoSums(nums, target):

    i = 0
    j = len(nums) - 1
    nums.sort()
    for x in range(0, len(nums)):
        if (nums[i] + nums[j]) > target:
            j = j - 1
        elif (nums[i] + nums[j]) < target:
            i = i + 1
        else:
            return ([nums[i], nums[j]])

if __name__ == '__main__':

    nums = [3, 1, 8, 12, 8, 13, 8, 65, 23]
    target = 77
    print(twoSums(nums, target))
