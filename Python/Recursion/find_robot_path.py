def get_path(maze):
    path = []
    if get_path_util(maze, len(maze)-1, len(maze[0])-1, path) == True:
        return path

def get_path_util(maze, r, c, path):

    if c < 0 or r < 0 or maze[r][c] == 0:
        return False

    # if r == 0 and c == 0 or get_path_util(maze,r,c-1,path) or get_path_util(maze,r-1,c,path):
    #     path.insert(0, [r,c])
    #     return True

    if get_path_util(maze,r-1,c,path) or r == 0 and c == 0 or get_path_util(maze,r,c-1,path):
        path.insert(0, [r,c])
        return True

    return False




if __name__ == '__main__':
    maze = [[1,1,1,1], [1,0,0,1], [0,0,1,1], [1,1,0,1]]

    path = get_path(maze)
    print(path)
