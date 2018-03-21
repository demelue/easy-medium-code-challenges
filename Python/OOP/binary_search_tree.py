class TreeNode(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

#modified for anagrams
def modified_insert(root, data):
    pass

def modified_search(root, data):
    pass

def insert(root, data):
    if root == None:
        root = TreeNode(data)
        return root
    if data <= root.data:
        root.left = insert(root.left, data)
    else:
        root.right = insert(root.right, data)
    return root

def search(root, data):
    if root == None or root.data == data:
        if root == None:
            print("Not Found")
            return False
        else:
            print("Found")
            return True
    if data <= root.data:
        search(root.right, data)
    else:
        search(root.left, data)

#Traversal
def print_in_order(root):
    if root == None:
        return
    print_in_order(root.left)
    print(root.data)
    print_in_order(root.right)

def print_post_order(root):
    if root == None:
        return
    print_post_order(root.left)
    print_post_order(root.right)
    print(root.data)

def print_pre_order(root):
    if root == None:
        return
    print(root.data)
    print_pre_order(root.left)
    print_pre_order(root.right)

def count_node(root):
    if root == None:
        return 0
    if root.left == None and root.right == None:
        return 1
    else:
        return 1 + count_node(root.left) + count_node(root.right)

if __name__ == '__main__':

    my_tree = None
    my_tree = insert(my_tree, 4)
    my_tree = insert(my_tree, 5)
    my_tree = insert(my_tree, 3)
    my_tree = insert(my_tree, 2)

    print(count_node(my_tree))
    print_in_order(my_tree)
