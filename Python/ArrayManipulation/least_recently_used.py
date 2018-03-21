class LeastRecentlyUsed(object):
    capacity = 0
    cache = []
    lru = []

    def __init__(self, lru_size):
        self.capacity = lru_size
        self.cache = [None]*lru_size

        for i in range(self.capacity):
            self.lru.append(i)

    def update_lru(self):
        for i in range(self.capacity):
            if self.lru[i] - 1 < 0:
                self.lru[i] = self.capacity - 1
            else:
                self.lru[i] -= 1

    def add(self, value):
        for i in range(self.capacity):
            if self.lru[i] == 0:
                self.cache[i] = value
        self.update_lru()


    def access(self, index):
        if self.lru[index] == 0:
            self.update_lru()
            return self.cache[index]

        if self.lru[index] >= 1 and self.lru[index] < self.capacity-1:
            temp = self.lru[index]
            for i in range(self.capacity):
                if self.lru[i] > temp:
                    self.lru[i] -= 1
            self.lru[index] = self.capacity-1
        return self.cache[index]

    def least_recently_used(self):
        for i in range(self.capacity):
            if self.lru[i] == 0:
                return self.cache[i]

    def print_lru(self):
        for i in range(self.capacity):
            print(self.lru[i],self.cache[i])

if __name__ == '__main__':

    my_cache = LeastRecentlyUsed(4)
    my_cache.add('A')
    my_cache.add('B')
    my_cache.add('C')
    my_cache.add('D')
    my_cache.add('E')
    my_cache.print_lru()
    print("Accessing:", my_cache.access(1))
    my_cache.print_lru()
    print("Accessing:", my_cache.access(1))
    my_cache.print_lru()
    # print("Accessing:", my_cache.access(0))
    # my_cache.print_lru()
    print("LRU:",my_cache.least_recently_used())
