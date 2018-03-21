def find_shortest_path(graph,a,b):

    queue = []
    parents = {}
    path = []

    if a == b:
        path = [a,b]
        return path
    queue.append(a)
    parents[a] = -1
    while queue:
        curr_node = queue.pop(0)
        if curr_node == b:
            break
        neighbors = graph[curr_node] #returns list of neighbors

        for n in neighbors:
            if n not in parents:
                queue.append(n)
                parents[n] = curr_node

    curr_node = b
    while curr_node != -1:
        path.insert(0, curr_node)
        curr_node = parents[curr_node]

    return path

def create_key(value):
    out = str(value[0]) + "_" + str(value[1])
    # print(out)
    return out

def find_shortest_path_bin_maze(maze,src,dest):
    queue = []
    parents = {}
    col_dim = len(maze[0])
    row_dim = len(maze)
    path = []

    if src == dest:
        path = [src, dest]
        return path
    queue.append(src)
    parents[create_key(src)] = [-1,-1]

    while queue:
        curr = queue.pop(0)
        print("current: ", curr)
        if curr == dest:
            print("last node: ",curr)
            break
        if curr[0]-1 >= 0 and maze[curr[0]-1][curr[1]] == 1:
            n = [curr[0]-1,curr[1]]
            if create_key(n) not in parents:
                queue.append([curr[0]-1,curr[1]])
                parents[create_key(n)] = curr
                print("neighbor added: ",curr)
        if curr[1]-1 >= 0 and maze[curr[0]][curr[1]-1] == 1:
            n = [curr[0],curr[1]-1]
            if create_key(n) not in parents:
                queue.append([curr[0],curr[1]-1])
                parents[create_key(n)] = curr
                print("neighbor added: ",curr)
        if curr[0]+1 < row_dim and maze[curr[0]+1][curr[1]] == 1:
            n = [curr[0]+1,curr[1]]
            if create_key(n) not in parents:
                queue.append([curr[0]+1,curr[1]])
                parents[create_key(n)] = curr
                print("neighbor added: ",curr)
        if curr[1]+1 < col_dim and maze[curr[0]][curr[1]+1] == 1:
            n = [curr[0],curr[1]+1]
            if create_key(n) not in parents:
                queue.append([curr[0],curr[1]+1])
                parents[create_key(n)] = curr
                print("neighbor added: ",curr)
    curr_node = dest
    while curr_node != [-1,-1]:
        path.insert(0,curr_node)
        curr_node = parents[create_key(curr_node)]
    return path

if __name__ == '__main__':

    # graph = [[3], [4,2], [], [1,2], [0]]
    # print(find_shortest_path(graph, 0, 2))

    bin_maze = [[1, 1, 1, 1, 1],
                [1, 0, 1, 0, 1],
                [1, 1, 1, 0, 1]]
    print(find_shortest_path_bin_maze(bin_maze,[0,0],[0,3]))
