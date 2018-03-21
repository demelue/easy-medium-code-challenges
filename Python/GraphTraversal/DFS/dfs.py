graph = [[1,2], [2], [0,3], [3]]

def dfs_util(node, visited):
    visited[node] = True
    # print(visited)
    print (node)

    for i in graph[node]:
        if visited[i] == False:
            dfs_util(i, visited)


def depth_first_search(start):
    visited = [False] * (len(graph))
    dfs_util(start, visited)


if __name__ == '__main__':

    depth_first_search(3)
