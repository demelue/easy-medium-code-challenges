import math

class coordinate(object):
    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.dist = 0

    def print_coordinate(self):
        print("x: " + str(self.x )+ " y: " + str(self.y) + " distance: " + str(self.dist))

class heap_max(object): #max heap
    def __init__(self, max_length):
        self.capacity = max_length
        self.size = 0
        self.heap = [None] * max_length

    def swap(self, i, j):
        tmp = self.heap[i]
        self.heap[i] = self.heap[j]
        self.heap[j] = tmp

    #NOTE: bubble up, position starts at size, pos+1/2 - 1
    def insert(self, object_value):
        if self.size == self.capacity:
            print("Full")
            return False

        self.heap[self.size] = object_value
        pos = self.size
        while pos > 0:
            parent = int((pos + 1)/2) - 1
            if self.heap[parent] >= self.heap[pos]:
                break
            else:
                self.swap(pos, parent)
                pos = parent
        self.size += 1
        return True

    #NOTE: bubble down, remove from parent 0, check right side first
    #left = 2*pos + 1, reduce size after extraction
    def extract(self):
        if self.size == 0:
            print("Empty")
            return None

        out_object = self.heap[0]
        self.heap[0] = self.heap[self.size - 1]
        self.size -= 1
        pos = 0
        while pos < int(self.size/2):
            left = 2 * pos + 1
            right = left + 1
            #validate right
            if right < self.size and self.heap[right] >= self.heap[left]:
                if self.heap[pos] >= self.heap[right]:
                    break
                self.swap(pos, right)
                pos = right
            else:
                if self.heap[pos] >= self.heap[left]:
                    break
                self.swap(pos, left)
                pos = left
        return out_object

    def peek(self):
        if self.size == 0:
            print("Empty")
            return None
        return self.heap[0]

class heap_min(heap_max):
    def __init__(self, max_length, x,y):
        super().__init__(max_length)
        self.x = x
        self.y = y

    def calculate_distance(self, destination):
        return math.sqrt(pow(abs(destination.x - self.x),2) + pow(abs(destination.y - self.y),2))

    #NOTE: bubble up, position starts at size, pos+1/2 - 1
    def insert(self, object_value):
        if self.size == self.capacity:
            print("Full")
            return False

        object_value.dist = self.calculate_distance(object_value)
        # print("Dist: " + str(object_value.dist))

        self.heap[self.size] = object_value
        pos = self.size
        while pos > 0:
            parent = int((pos + 1)/2) - 1
            if self.heap[parent].dist <= self.heap[pos].dist:
                break
            else:
                self.swap(pos, parent)
                pos = parent
        self.size += 1
        return True

    #NOTE: bubble down, remove from parent 0, check right side first
    #left = 2*pos + 1, reduce size after extraction
    def extract(self):
        if self.size == 0:
            print("Empty")
            return None

        out_object = self.heap[0]
        self.heap[0] = self.heap[self.size - 1]
        self.size -= 1
        pos = 0
        while pos < int(self.size/2):
            left = 2 * pos + 1
            right = left + 1
            #validate right
            if right < self.size and self.heap[right].dist <= self.heap[left].dist:
                if self.heap[pos].dist <= self.heap[right].dist:
                    break
                self.swap(pos, right)
                pos = right
            else:
                if self.heap[pos].dist <= self.heap[left].dist:
                    break
                self.swap(pos, left)
                pos = left
        return out_object

if __name__ == '__main__':
    values = [4,8,2,1,9,-7]
    max_heap_test = heap_max(6)
    for i in range(len(values)):
        max_heap_test.insert(values[i])

    for i in range(len(values)):
        print(max_heap_test.extract())

    #find closest coordinate to the source_x and source_y
    source_x = 0
    source_y = 0
    coordinate_list = [coordinate(1,2), coordinate(2,1), coordinate(-1,0), coordinate(3,0)]
    func_closest_coordinate = heap_min(len(coordinate_list),source_x,source_y)
    for coord in coordinate_list:
        func_closest_coordinate.insert(coord)

    out = func_closest_coordinate.extract()
    out.print_coordinate()
