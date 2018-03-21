def overlapping_intervals(intervals):
    overlap_count = 0
    overlap_index = []
    for i in range(0, len(intervals)-1):
        print(str(i) + " : " + str(intervals[i]))
        if check_for_overlap(intervals[i], intervals[i + 1]):
            overlap_count += 1
            overlap_index.append(i)
    if check_for_overlap(intervals[0], intervals[len(intervals)-1]):
        overlap_count += 1
        overlap_index.append(len(intervals)-1)
    if len(overlap_index) == len(intervals):
        return len(overlap_index) - 1
    else:
        return len(overlap_index)

def check_for_overlap(point1, point2):
    if (point1[0] == point2[0] or point1[1] == point2[1]):
        return True
    else:
        return False

if __name__ == '__main__':
    # intervals = [[1,2], [2,3], [3,4], [1,3]]
    intervals = [[1,2], [1,2], [1,2]]
    print(overlapping_intervals(intervals))
