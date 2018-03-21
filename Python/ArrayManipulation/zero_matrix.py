def zero_matrix(mat):
    flag = False
    for row in range(len(mat)):
        for col in range(len(mat[row])):
            if mat[row][col] == 1:
                flag = True
                break
        if flag:
            break

    for i in range(len(mat)):
        mat[i][col] = 1

    for j in range(len(mat[row])):
        mat[row][j] = 1

    for m in range(len(mat)):
        print(mat[m])

#store row state in the first col of that row
#store col state in the first row of that col, however for row0 and col0 it would be mat[0][0]
#therefore create a bool for column zero
def zero_matrix_v2(mat):
    col_0_status = False
    row = len(mat)
    col = len(mat[0])

    for i in range(row):
        for j in range(1,col):
            if mat[i][0] == 0:
                col_0_status = True
            if mat[i][j] == 0:
                mat[i][0] = 0
                mat[0][j] = 0

    i = row-1
    j = col-1

    while i >= 0:
        while j >= 1:
            if mat[i][0] == 0 or mat[0][j] == 0:
                mat[i][j] = 0
            j -= 1
        if col_0_status:
            mat[i][0] = 0
        i -= 1
        j = col-1

    for m in range(len(mat)):
        print(mat[m])

if __name__ == '__main__':
    # matrix = [[1,0,0,0],
    #           [0,0,0,0],
    #           [0,0,0,0],
    #           [0,0,0,0]]
    # zero_matrix(matrix)
     matrix = [[1,1,1],
               [1,1,1],
               [1,0,1]]
     zero_matrix_v2(matrix)
