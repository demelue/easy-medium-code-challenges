#brute force
def find_max_square(matrix):
    row_dim = len(matrix)
    col_dim = len(matrix[0])
    max_sq_len = 0
    for r in range(row_dim):
        for c in range(col_dim):
            if matrix[r][c] == 1:
                flag = True
                sq_len = 1
                while sq_len + r < row_dim and sq_len + c < col_dim and flag: #find more 1's
                    #check next box along col
                    # print(r,c,sq_len)
                    for k in range(c,sq_len + c + 1):
                        # print("col index: ",r + sq_len,k)
                        if matrix[r + sq_len][k] == 0:
                            flag = False
                            break
                    #check next box along row
                    for k in range(r,sq_len + r + 1):
                        # print("row index: ",k,c+sq_len)
                        if matrix[k][c + sq_len] == 0:
                            flag = False
                            break

                    if flag:
                        sq_len += 1
                if sq_len > max_sq_len:
                    max_sq_len = sq_len

    print("Maximum sub matrix: ", max_sq_len * max_sq_len)

if __name__ == '__main__':
    mat = [[0,0,1,0],
           [1,1,1,0],
           [0,1,1,1],
           [1,1,1,0]]

    find_max_square(mat)
