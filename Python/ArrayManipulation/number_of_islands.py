def create_key(r,c):
    return str(r) + '_' + str(c)

def get_neighbors(land,r,c):
    n_list = []
    if r - 1 <= 0 and land[r - 1][c] == 1:
        n_list.append([r-1,c])
    if r + 1 < len(land) and land[r + 1][c] == 1:
        n_list.append([r+1,c])
    if c - 1 <= 0 and land[r][c-1] == 1:
        n_list.append([r,c-1])
    if c + 1 < len(land[r]) and land[r][c+1] == 1:
        n_list.append([r,c+1])
    return n_list

#BFS
def number_of_islands_v1(land):
    visited = {}
    queue = []
    island_count = 0

    for r in range(len(land)):
        for c in range(len(land[r])):
            if create_key(r,c) not in visited and land[r][c] == 1:
                queue.append([r,c])
                visited[create_key(r,c)] = 1
                while queue:
                    c_node = queue.pop(0)
                    neighbors = get_neighbors(land,c_node[0],c_node[1])
                    for n in neighbors:
                        if create_key(n[0],n[1]) not in visited:
                            queue.append(n)
                            visited[create_key(n[0],n[1])] = 1
                island_count += 1
    return island_count

def dfs_util(land, r, c):
    if r < 0 or c < 0 or r >= len(land) or c >= len(land[r]) or land[r][c] == 0:
        return
    land[r][c] = 0 #mark visited points in the grid
    dfs_util(land, r+1, c)
    dfs_util(land, r-1, c)
    dfs_util(land, r, c+1)
    dfs_util(land, r, c-1)

#DFS
def number_of_islands_v2(land):
    count = 0
    for r in range(len(land)):
        for c in range(len(land[r])):
            if land[r][c] == 1:
                dfs_util(land, r, c)
                count += 1
    return count

if __name__ == '__main__':

    land1 = [[1,0,1],
            [0,1,0],
            [0,0,0]]

    land2 = [[1,1,0,1],
            [0,1,0,0],
            [1,0,0,0],
            [0,0,1,0]]

    land3  = [[1,1,1,1,0],
             [1,1,0,1,0],
             [1,1,0,0,0],
             [0,0,0,0,0]]

    # print(number_of_islands_v1(land1))
    print(number_of_islands_v2(land3))
