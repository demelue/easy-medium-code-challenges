def is_valid(s):
    # "(){}[]"
    # stack = (
    # bracket = )
    parentheses_dict = {"}":"{", ")":"(", "]":"["}
    stack = []
    for bracket in s:
        if bracket in parentheses_dict.values():
            stack.append(bracket)
        elif bracket in parentheses_dict.keys():
            if stack == []:
                return False
            if stack.pop() != parentheses_dict[bracket]:
                return False
        else:
            return False
    return stack == []

def isValid(s):
    stack = []
    mydict = {"]":"[", "}":"{", ")":"("}
    for char in s:
        if char in mydict.values():
            stack.append(char)
        elif char in mydict.keys():
            if stack == [] or mydict[char] != stack.pop():
                return False
        else:
            return False
    return stack == []

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

if __name__ == '__main__':
    # print(is_valid("{([])}"))
    # print(isValid("{([])}"))
