def find_path_util(a, r, c, path):
    print(r,c)
    if r < 0 or c < 0 or a[r][c] == 0:
        return False

    if find_path_util(a,r-1,c,path) or r == 0 and c == 0 or find_path_util(a,r,c-1,path):
        path.insert(0,[r,c])
        return True


    return False

def find_path(a):
    row = len(a)
    col = len(a[0])
    path = []
    if find_path_util(a, row-1, col-1, path):
        print(path)
    else:
        print("No path")

def find_all_paths_util(a,r,c,path):
    if r == 0 and c == 0:
        path.append([r,c])
        return True

    flag = False
    if r >= 1 and a[r-1][c] != 0:
        flag = find_all_paths_util(a,r-1,c,path)

    if c >= 1 and a[r][c-1] != 0:
        flag = find_all_paths_util(a,r,c-1,path)

    if flag:
        path.append([r,c])
    return flag

def find_all_paths(a):
    path = []
    r = len(a)-1
    c = len(a[0])-1
    path_count = 0
    find_all_paths_util(a,r,c,path)
    for coordinate in path:
        if coordinate == [0,0]:
            path_count += 1
    return path_count;
    
if __name__ == '__main__':
    mat = [[1,1,1,1],
           [1,1,1,1],
           [1,1,1,1]]
    # find_path(mat)

    print(find_all_paths(mat))
