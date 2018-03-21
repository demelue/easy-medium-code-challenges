
#use the complement as key use index as value

def twoSums(nums, target):

    myDict = {}
    for i in range(0, len(nums)):
        if nums[i] in myDict:
            return [myDict[nums[i]], i]
        else:
            myDict[target-nums[i]] = i

if __name__ == '__main__':
    nums = [2, 3, 1, 7, 5, 9]
    target = 4
    print(twoSums(nums, target))
