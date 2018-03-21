def print_lower_left_triange(mat):

    for i in range(len(mat)):
        size = i + 1
        j = 0
        while j < size:
            print(mat[i][j])
            j += 1


def print_upper_right_triangle(mat):
    size = len(mat[0])
    for i in range(len(mat)):
        j = 0
        while j < size:
            print(mat[i][j])
            j += 1
        size -= 1


if __name__ == '__main__':
    matrix = [[1,2,3,4],
              [5,6,7,8],
              [9,10,11,12],
              [13,14,15,16]]
    print_lower_left_triange(matrix)
    print_upper_right_triangle(matrix)
