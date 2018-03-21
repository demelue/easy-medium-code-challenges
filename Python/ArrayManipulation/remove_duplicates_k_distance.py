def remove_duplicates(nums, k):

    buffdict = {}
    output = []
    for i, val in enumerate(nums):
        if val not in buffdict:
            buffdict[val] = i #add to dictionary
            output.append(val)
        else:
            if (abs(buffdict[val] - i) < k):
                buffdict[val] = i #update
                print("duplicate " + str(val))
            else:
                buffdict[val] = i #update
                output.append(val)
    return output

if __name__ == '__main__':
    nums = [1,1,2,2,3,2,2,2,4,1,1,8]
    k = len(nums)
    print(remove_duplicates(nums,k))
