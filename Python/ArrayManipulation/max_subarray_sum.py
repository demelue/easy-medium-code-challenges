# returns the contiguous subarray with the largest sum
def max_subarray_sum_v1(nums):
    curr_sum = max_sum = nums[0]
    for i,num in enumerate(nums,start=1):
        curr_sum = max(num, curr_sum + num)
        # if num > curr_sum + num:
        #     curr_sum = num
        # else:
        #     curr_sum += num
        max_sum = max(curr_sum, max_sum)
        # if curr_sum > max_sum:
        #     max_sum = curr_sum
    return max_sum
if __name__ == '__main__':
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print(max_subarray_sum_v1(nums))
