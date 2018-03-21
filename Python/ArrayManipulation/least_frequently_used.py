class LeastFrequentlyUsed(object):
    lfu_dict = {}

    def __init__(self):
        pass

    def add(self,value):
        if value not in self.lfu_dict:
            self.lfu_dict[value] = 0

    def access(self,value):
        if value in self.lfu_dict:
            self.lfu_dict[value] += 1

    def least_frequently_used(self):
        frequency = 0
        output = []

        while frequency <= max([j for j in self.lfu_dict.values()]):
            if frequency in self.lfu_dict.values():
                for i in self.lfu_dict:
                    if self.lfu_dict[i] == frequency:
                        output.append(i)
                break
            frequency += 1
        return output

    def print_lfu(self):
        for value in self.lfu_dict:
            print(value,self.lfu_dict[value])

if __name__ == '__main__':
    my_cache = LeastFrequentlyUsed()
    for i in range(5):
        my_cache.add(chr(i+65))

    my_cache.access('A')
    my_cache.access('B')
    my_cache.access('D')
    my_cache.access('B')
    my_cache.print_lfu()
    print("least frequently used:",my_cache.least_frequently_used())
