def evaluate_expression(val1,val2,operation):
    if operation == '*':
        return val1 * val2
    elif operation == '/':
        return val2/val1
    elif operation == '+':
        return val1 + val2
    else:
        return val2 - val1

#use 'type(i) is int/long/float' for a more generic answer
def reverse_polish_notation(expression):
    stack = []
    val1 = 0
    val2 = 0
    for operation in expression:
        if operation == "*" or operation == "/" or operation == "+" or operation == "-":
            val1 = stack.pop()
            val2 = stack.pop()
            stack.append(evaluate_expression(val1,val2,operation))
        else:
            stack.append(int(operation))
            # print(stack)
    return int(stack.pop())

if __name__ == '__main__':
    data = ["2", "1", "+", "3", "*"]
    print("Answer: ",reverse_polish_notation(data))
    data = ["4", "13", "5", "/", "+"]
    # data = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    print("Answer: ",reverse_polish_notation(data))
