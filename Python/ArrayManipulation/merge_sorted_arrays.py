
def m_sorted_arrays(arrA, arrB, alen, blen):
    if alen + blen > len(arrA):
        return

    a_index = alen-1
    b_index = blen-1
    m_index = alen + blen - 1

    while a_index >= 0 and b_index >= 0:
        if arrA[a_index] > arrB[b_index]:
            arrA[m_index] = arrA[a_index]
            a_index -= 1
        else:
            arrA[m_index] = arrB[b_index]
            b_index -= 1

        m_index -= 1
    while b_index >= 0:
        arrA[m_index] = arrB[b_index]
        b_index -= 1
        m_index -= 1

    return arrA

if __name__ == '__main__':
    numsA = [2, 4, 6, 7, 0, 0, 0]
    numsB = [1, 3, 5]
    print(m_sorted_arrays(numsA,numsB,4,3))
