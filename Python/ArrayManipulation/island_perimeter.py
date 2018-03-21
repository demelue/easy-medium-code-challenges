def create_key(node):
    return str(node[0]) + '_' + str(node[1])

def get_neigbors(island, node):
    n = []

    r = len(island)
    c = len(island[0])
    x = node[0]
    y = node[1]

    if x - 1 >= 0 and island[x-1][y] == 1:
        n.append([x-1,y])
    if x + 1 < r and island[x + 1][y] == 1:
        n.append([x+1,y])
    if y - 1 >= 0 and island[x][y-1] == 1:
        n.append([x,y-1])
    if y + 1 < c and island[x][y+1] == 1:
        n.append([x,y+1])

    return n

#NOTE: GUARANTEED ONLY 1 ISLAND ON ENTIRE MAP
def island_perimeter_v1(island):
    start_node = [0,0]
    for r in range(len(island)):
        for c in range(len(island[r])):
            if island[r][c] == 1:
                 start_node = [r,c]
                 flag = True
                 break
        if flag:
            break
    print(start_node)
    queue = []
    visited = {}
    perimeter = 0
    queue.append(start_node)
    visited[create_key(start_node)] = [-1,-1]

    while queue:
        curr_node = queue.pop(0)
        neighbors = get_neigbors(island,curr_node)
        perimeter += (4 - len(neighbors))
        for n in neighbors:
            if create_key(n) not in visited:
                queue.append(n)
                visited[create_key(n)] = curr_node
    print("perimeter: ", perimeter)

def island_perimeter_v2(island):
    island_count = 0
    neighbors = 0
    print(len(island),len(island[0]))
    for r in range(len(island)):
        for c in range(len(island[r])):
            if island[r][c] == 1:
                island_count += 1
                if r < len(island) - 1 and island[r + 1][c] == 1:
                    neighbors += 1
                if c < len(island[0]) - 1 and island[r][c + 1] == 1:
                    neighbors += 1
    perimeter = island_count * 4 - neighbors * 2
    print("perimeter: ", perimeter)
    return perimeter

if __name__ == '__main__':
    island = [[0,1,0,0],
              [1,1,1,0],
              [0,1,0,0],
              [1,1,0,0]]

    # island_perimeter_v1(island)
    # island_perimeter_v2(island)

    island = [[1,1,1,0],
              [1,1,1,0],
              [0,1,0,0],
              [0,0,0,0]]

    island_perimeter_v1(island)
    island_perimeter_v2(island)
