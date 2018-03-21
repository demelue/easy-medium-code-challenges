def swap(nums,i,j):
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp
    return nums
#TIme O(N*K)
def k_sort(nums,k):
    i = 0
    j = 1

    while i < len(nums):
        if i + j < len(nums) and nums[i + j] < nums[i]:
            nums = swap(nums,i,j+i)

        j += 1
        if j > k:
            j = 1
            i += 1
    print(nums)

if __name__ == '__main__':

    nums = [3,4,2,1,6,5] #k = 3
    # nums = [9,5,12,49,57,10,1,2] #k = 7
    k = 3
    k_sort(nums,k)
