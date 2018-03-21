def simplify_path_v1(path):
    index = len(path) - 1
    pathlist = list(path)
    # print(len(pathlist))
    if pathlist[index] != "/":
        return None

    if pathlist[len(path)-2] == ".":
        return "/"

    slash_counter = 0
    while index >= 0:
        if pathlist[index] == "/":
            if pathlist[index - 1] == "/":
                slash_counter += 1
            slash_counter += 1
            if slash_counter == 2:
                return ''.join(pathlist[index:-1])

        if slash_counter == 3:
            del pathlist[index - 1]
            j = index - 2
            while j >= 0:
                if pathlist[j] == "/":
                    return ''.join(pathlist[j:-1])
                j -= 1
            break
        index -= 1

def simplify_path_v2(path):
    stack = []
    for p in path.split("/"):
        if p == "..":
            if stack:
                stack.pop()
        elif p and p != '.':
            stack.append(p)
    return "/" + "/".join(stack)

if __name__ == '__main__':
    print(simplify_path_v1("/a/./b/../../c/"))
    print(simplify_path_v1("/start/f/home/../"))
    print(simplify_path_v1("/start/folder/here/Demelue/"))
    print(simplify_path_v1("/start/f./home//gov/"))
    # print(simplify_path_v2("/start/f/home/../"))
    # print(simplify_path_v2("/start/home//gov/"))
    # print(simplify_path_v2("/a/./b/../../c/"))
    # print(simplify_path_v2("/start/folder/here/Demelue/"))
