class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def add_to_head(data, head):
    temp = Node(data)
    if head == None:
        return temp
    temp.next = head
    return temp

def add_to_tail(data, head):
    temp = head
    tail = Node(data)
    while temp.next != None:
        temp = temp.next
    temp.next = tail
    return head

def print_list(head):
    temp = head
    while temp != None:
        print(temp.data)
        temp = temp.next


if __name__ == '__main__':
    linked_list_head = None
    for i in range(5):
        linked_list_head = add_to_head(i, linked_list_head)
    linked_list_head = add_to_tail(12, linked_list_head)

    print_list(linked_list_head)
