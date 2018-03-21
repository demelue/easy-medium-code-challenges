def print_spiral(mat, M, N):
    row_end = M
    col_end = N
    row_start = 0
    col_start = 0
    i = 0
    while row_start < row_end and col_start < col_end:

        #print first row
        print("Top")
        i = col_start
        while i < col_end:
            print(row_start,i)
            i += 1

        row_start += 1

        print("Right")
        i = row_start
        while i < row_end:
            print(i,col_end-1)
            i += 1

        col_end -= 1

        if row_start < row_end:
            print("Bottom")
            i = col_end-1
            while i >= col_start:
                print(row_end-1,i)
                i -= 1

            row_end -= 1

        if col_start < col_end:
            print("Left")
            i = row_end-1
            while i <= row_start:
                print(i,col_start)
                i += 1

            col_start += 1


if __name__ == '__main__':
    mat = [[1,2,3],[4,5,6],[7,8,9]]
    # mat = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    print_spiral(mat, 3,3)

# n = int(input())
# for i in range(n):
#     a, b = input().strip().split(' ')
#     print (int(a) + int(b))
