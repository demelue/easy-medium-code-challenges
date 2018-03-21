class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
    @classmethod
    def create_interval(cls, start, stop):
        return cls(start,stop)

def merge_intervals_v1(intervals):
    interval_list = []
    for i in intervals:
        interval_list.append([i.start,i.end])
    print("original: ", interval_list)

    if interval_list:
        sorted_list = sorted(interval_list)
    print("sorted: ", sorted_list)
    j = 0
    while j < len(sorted_list) - 1:
        if sorted_list[j][1] >= sorted_list[j+1][0]:
            print("Merge")
            sorted_list[j + 1][0] = sorted_list[j][0]
            sorted_list.pop(j)
        else:
            j += 1
        # print(sorted_list)
    interval_object = Interval()
    coordinate_list = []
    for coordinate in sorted_list:
        coordinate_list.append(interval_object.create_interval(coordinate[0],coordinate[1]))

    for val in coordinate_list:
        print(val.start, val.end)

def merge_intervals_v2(intervals):
    interval_list = []
    for i in intervals:
        interval_list.append([i.start,i.end])
    print("original: ", interval_list)
    if interval_list:
        sorted_list = sorted(interval_list)
    print("sorted: ", sorted_list)

    start = sorted_list[0][0]
    end = sorted_list[0][1]
    output = []
    for val in sorted_list:
        curr_start = val[0]
        curr_end = val[1]
        if curr_start <= end:
            end = max(end, curr_end)
        else:
            output.append([start,end])
            start = curr_start
            end = curr_end
    output.append([start,end])
    print(output)

if __name__ == '__main__':

    l0 = Interval(5,10)
    l1 = Interval(1,3)
    l2 = Interval(15,18)
    l3 = Interval(2,6)

    interval_obj = [l0, l1, l2, l3]
    merge_intervals_v1(interval_obj)
    merge_intervals_v2(interval_obj)
