def array_rotation(nums, d):

    out = nums[d:] + nums[:d-len(nums)]
    return out;

if __name__ == '__main__':
    nums = [1,2,3,4,5]
    print(array_rotation(nums, 3))
