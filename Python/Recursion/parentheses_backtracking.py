def validate_parentheses(s):
    i = 0
    if s[i] == ')':
        return False
    count = 1
    i += 1
    while i < len(s):
        if s[i] == '(':
            count += 1
        else:
            if count > 0:
                count -= 1
            else:
                return False
        i += 1

    if count < 0:
        return False
    else:
        return True

def swap(i,j,s):
    s = list(s)
    tmp = s[i]
    s[i] = s[j]
    s[j] = tmp
    return "".join(s)

def gen_parenthesis_util(s,i,result):
    if i == len(s):
        # print(s)
        if validate_parentheses(s) and s not in result:
            result.append(s)
    else:
        for j in range(i,len(s)):
            s = swap(i,j,s)
            gen_parenthesis_util(s,i + 1, result)
            s = swap(i,j,s)

#recursively generate all permutations of parenthesis pair and validate each one
def generate_wellformed_parentheses(n):
    s = ""
    for i in range(n):
        s += "()"
    result = []
    i = 0
    gen_parenthesis_util(s,i,result)
    print("Valid: ", result)

#add a condition to only generate valid pairs
#backtracking technique
def generate_parentheses_backtrack_util(s, output, open_count, close_count, max_count):
    if len(s) == 2*max_count:
        output.append(s)
        return
    if open_count < max_count:
        generate_parentheses_backtrack_util(s + "(", output, open_count + 1, close_count, max_count)

    if close_count < open_count:
        generate_parentheses_backtrack_util(s + ")", output, open_count, close_count + 1, max_count)

def generate_parentheses_backtrack(n):
    output = []
    generate_parentheses_backtrack_util("",output, 0, 0, n)
    print("Valid: ", output)

if __name__ == '__main__':
    # print(validate_parentheses('()()'))
    generate_wellformed_parentheses(3)
    generate_parentheses_backtrack(3)
