#how many values do i remove to make a = b 
def make_an_anagram(a, b):
    blist = list(b)
    common = []
    not_common = []
    for aval in a:
        if aval in blist:
            common.append(aval)
            blist.remove(aval)
        else:
            not_common.append(aval)
    return (abs(len(a)-len(common)) + abs(len(b)-len(common)))


    # print(abs(len(astr) - duplicate_count) + abs(len(bstr) - duplicate_count))


if __name__ == '__main__':
    a = "affdgt"
    b = "efgh"
    # make_an_anagram(a, b)
    print(make_an_anagram(b, a))
