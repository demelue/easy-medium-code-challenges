#     1
#    1 1
#   1 2 1
#  1 3 3 1
# 1 4 6 4 1

def pascals(num):
    output = []
    for i in range(num):
        output.append([ 1 for j in range(i + 1)])
        for k in range(1,i):
            output[i][k] = output[i-1][k-1] + output[i-1][k]
    return output[num-1]
if __name__ == '__main__':
      print(pascals(6))
