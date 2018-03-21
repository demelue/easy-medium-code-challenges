#brute force
def find_product_of_all_values_except_index(nums):
    output = []
    current_product_index = 0

    for i in range(0, len(nums)):
        current_product = 1
        for j in range(0, len(nums)):
            if j != i:
                current_product *= nums[j]
        output.append(current_product)

    return output

def find_product_of_all_values_except_index_greedy(nums):
    output = [None] * len(nums)
    j = len(nums)-1

    current_product = 1
    for i in range(0, len(nums)):
        output [i] = current_product
        current_product *= nums[i]

    current_product = 1
    while j >= 0:
        output[j] *= current_product
        current_product *= nums[j]
        j -= 1
    print(output)

if __name__ == '__main__':
    nums = [1, 7, 3, 4]
    # print(find_product_of_all_values_except_index(nums))
    find_product_of_all_values_except_index_greedy(nums)
