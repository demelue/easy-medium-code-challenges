phone_digits = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}

def print_combination(index_array, digits):
    out = ""
    for i,n in enumerate(digits):
        out += phone_digits[n][index_array[i]]
    print(out)

def letter_combination_v1(value):
    combination_indices = [0]*len(value)

    #find number of combinations
    iter_count = 1
    for letter in value:
        iter_count *= len(phone_digits[letter])

    print("Number of iterations: ", iter_count)

    curr_index = 0 #current index for index array
    for i in range(iter_count):
        print_combination(combination_indices,value)
        combination_indices[curr_index] += 1
        while combination_indices[curr_index] == len(phone_digits[value[curr_index]]) and curr_index < len(combination_indices) - 1:
            combination_indices[curr_index] = 0
            curr_index += 1
            combination_indices[curr_index] += 1
        curr_index = 0

def letter_combination_v2(digits):
    pass

if __name__ == '__main__':
    letter_combination_v1('23')
