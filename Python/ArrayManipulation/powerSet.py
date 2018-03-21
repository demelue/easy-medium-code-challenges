from itertools import chain, combinations

def powerSet(s):
    out = []

    for i in range(0, 1 << len(s)):
        out.append([s[j] for j in range(0, len(s)) if (i & (1 << j))])
    return out

# def pset(myset):
#     s  = list(myset)
#     powerset = chain.from_iterable(combinations(s,r) for r in range(0,len(s)+1))
#     for x in powerset:
#         print(x)

if __name__ == '__main__':
    print(powerSet("xyz"))
    # pset("cde")
