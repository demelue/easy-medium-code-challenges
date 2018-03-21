def power_set_util(nums, tlist, start):
    print(tlist)
    i = start
    while i < len(nums):
        tlist.append(nums[i])
        power_set_util(nums, tlist, i + 1)
        tlist.pop(-1)
        i += 1

def power_set(nums):
    start = 0
    power_set_util(nums, [], start)

if __name__ == '__main__':
    nums = [1,2,3]
    power_set(nums)
