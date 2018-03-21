# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates

#BFS
def employee_importance(employees, unique_id):
    """
    :type employees: Employee
    :type id: int
    :rtype: int
    """
    total_importance = 0
    queue = []
    for emp in employees:
        if emp.id == unique_id:
            queue.append(emp)
            break
    while queue:
        curr = queue.pop(0)
        total_importance += curr.importance
        for val in employees:
            if val.id in curr.subordinates:
                queue.append(val)


    return total_importance

#DFS


if __name__ == '__main__':
    unique_id = 1
    #id, importance, subordinate
    data = [Employee(1,5,[2,3]), Employee(2,3,[]), Employee(3,3,[192]), Employee(192,9,[])]

    print("total importance: ", employee_importance(data, unique_id))
