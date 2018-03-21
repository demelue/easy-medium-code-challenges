class heap_node(object):
    def __init__(self, word, freq):
        self.word = word
        self.freq = freq

class max_heap(object):
    def __init__(self, max_length):
        self.size = 0
        self.capacity = max_length
        self.heap = [None]*max_length

    def swap(self, i, j):
        tmp = self.heap[i]
        self.heap[i] = self.heap[j]
        self.heap[j] = tmp

    def peek(self):
        return self.heap[size]

    def insert(self, node):
        # ((pos + 1)/2) - 1
        if self.size == self.capacity:
            return False

        pos = self.size
        self.heap[self.size] = node
        # print("Inserting: ", node.word)
        while pos > 0:
            parent = int(((pos + 1)/2) - 1)
            if self.heap[parent].freq >= self.heap[pos].freq:
                break
            else:
                self.swap(parent, pos)
                pos = parent
        self.size += 1
        return True

    def extract(self):
        # 2*pos + 1
        if self.size == 0:
            return None
        result = self.heap[0]
        self.heap[0] = self.heap[self.size - 1]
        #bubble down
        self.size -= 1
        pos = 0
        while pos < self.size/2:
            left = 2*pos + 1
            right = left + 1

            if right < self.size and self.heap[right].freq >= self.heap[left].freq:
                #right side
                if self.heap[pos].freq >= self.heap[right].freq:
                     break
                else:
                    self.swap(pos,right)
                    pos = right
            else:
                #left side
                if self.heap[pos].freq >= self.heap[left].freq:
                    break
                else:
                    self.swap(pos,left)
                    pos = left
        return result



def word_frequency(words):
    word_dict = {}
    for word in words:
        if word not in word_dict:
            word_dict[word] = 1
        else:
            word_dict[word] += 1
    return word_dict

def combine_word_freq(word_freq_dict):
    combine_word_dict = {}
    for curr_key in word_freq_dict:
        curr_val = word_freq_dict[curr_key]
        if curr_val not in combine_word_dict:
            combine_word_dict[curr_val] = [curr_key]
        else:
            combine_word_dict[curr_val].append(curr_key)
    return combine_word_dict

#list is sorted in this case
def top_k_frequent_word_v1(words, k):
    word_freq_dict = word_frequency(words)
    combine_word_dict = combine_word_freq(word_freq_dict)

    pq = []
    for curr_key in combine_word_dict:
        pq.append((curr_key, sorted(combine_word_dict[curr_key])))
    pq.sort(reverse=True)

    for i in range(k):
        print(pq[i][1])

#would require combine_word_freq to sort each time a new entry is combined
def top_k_frequent_word_v2(words, k):
    word_freq_dict = word_frequency(words)
    combine_word_dict = combine_word_freq(word_freq_dict)

    bin_max_heap = max_heap(len(set(words)))
    for freq in combine_word_dict:
        bin_max_heap.insert(heap_node(combine_word_dict[freq], freq))

    for i in range(k):
        val = bin_max_heap.extract()
        print(val.word)

if __name__ == '__main__':
    words = ["is", "this", "is", "a", "freq", "the", "is", "word", "this", "a"]

    # top_k_frequent_word_v1(words, 1)
    top_k_frequent_word_v2(words, 2)
