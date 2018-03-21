def combination_sum_util(nums, temp_list, remainder, start):
    if remainder < 0: #subtracted too many times
        return
    elif remainder == 0: #found the sum of values to produce target
        print(temp_list)
    else: #haven't found so keep computing
        i = start
        while i < len(nums):
            temp_list.append(nums[i])
            combination_sum_util(nums, temp_list, remainder-nums[i], i) # not i + 1 because we have to try the same value multiple times
            temp_list.pop(-1)
            i += 1

def combination_sum(nums, target):
    temp_list = []
    nums.sort()
    combination_sum_util(nums, temp_list, target, 0)


if __name__ == '__main__':
    nums = [2,3,6,7]
    target = 7
    combination_sum(nums,7)
