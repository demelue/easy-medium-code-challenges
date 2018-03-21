def zigzag(matrix):
    for i in range(len(matrix)):
        if i % 2 != 0:
            j = len(matrix[0]) - 1
            while j >= 0:
                print(matrix[i][j])
                j -= 1
        else:
            j = 0
            while j < len(matrix[0]):
                print(matrix[i][j])
                j += 1


if __name__ == '__main__':
    matrix = [[1,2,3,4],
               [8,7,6,5],
               [9,10,11,12],
               [16,15,14,13]]
    zigzag(matrix)
